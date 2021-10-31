//
// Created by HP on 2021/10/24.
//

#include "Expression.h"

Expression::Expression(std::string str) {
    origin_exp=str;
}

Expression::~Expression() = default;

//预处理：括号匹配与单目负处理
void Expression::PreProcessing() {
    BracketPreprocessing();
    NegativePreprocessing();
}

//表达式初分析与分离单元
bool Expression::Check_Split() {
    std::string::size_type i = 0;
    std::string::size_type temp = 0;
    std::string::size_type temp_a = -1;
    while (i<origin_exp.size())
    {
        std::string str_temp;
        str_temp += origin_exp[i];
        bool getPoint = false; //小数点标识符
        bool getSci = false; //科学记数法标识符
        if (isdigit(origin_exp[i])||origin_exp[i]=='P'||origin_exp[i]=='E'||origin_exp[i]=='e'){//读到数字或E或P(I),进行数字单元分析
            temp = i;
            do
            {
                if(origin_exp[i] == '.'){//小数点判断
                    getPoint = true;
                }
                if(origin_exp[i]=='e'){//科学记数法e判断
                    getPoint = false;
                    getSci = true;
                    temp_a=i;
                }
                if (++i >= origin_exp.size()) break;
            } while (isdigit(origin_exp[i]) || ((!getPoint) && origin_exp[i] == '.')||((!getSci) && origin_exp[i] == 'e')||(getSci && origin_exp[i]=='-')||origin_exp[i]=='I');
            if(origin_exp[i-1]!='.'){//当前最后一位不为小数点
                if(temp_a!=-1&&origin_exp.substr(temp,temp_a-temp)=="PI"){//插入宏定义PI
                    exp.push_back(character{ 0,0,0, PI+origin_exp.substr(temp_a, i - temp_a)});
                }
                else if(temp_a!=-1&&origin_exp.substr(temp,temp_a-temp)=="E"){//插入宏定义E
                    exp.push_back(character{ 0,0,0, E+origin_exp.substr(temp_a, i - temp_a) });
                }
                else if(temp_a == temp){
                    throw std::runtime_error(ExpressionError::ILLEGAL_CHARACTER_ERROR);
                }
                else {
                    std::string t=origin_exp.substr(temp, i - temp);
                    if(t=="PI"){
                        exp.push_back(character{0, 0, 0, PI});
                    }
                    else if(t=="E"){
                        exp.push_back(character{0, 0, 0, E});
                    }
                    else{
                        exp.push_back(character{0, 0, 0, t});
                    }
                }
            }
            else{
                throw std::runtime_error(ExpressionError::ILLEGAL_CHARACTER_ERROR);//否则输出非法字符
            }
        }
        else if (origin_exp[i] == '.') //读取到不在数字之后的小数点，抛出异常
            throw std::runtime_error(ExpressionError::ILLEGAL_CHARACTER_ERROR);
        else if (CHARACTER.find(str_temp)!=CHARACTER.end()) {//判断操作符单元
            if(CHARACTER.at(str_temp).operand==1 && (exp.rbegin()->type!=0||exp.empty())){//左结合单目运算符不在数字后，抛出异常
                throw std::runtime_error(ExpressionError::ILLEGAL_CHARACTER_ERROR);
            }
            exp.push_back(CHARACTER.at(str_temp));
            ++i;
        }
        else if (isalpha(origin_exp[i])){ //查找函数名，如sin等
            temp = i;
            do
            {
                if (++i >= origin_exp.size()) break;
            } while (isalpha(origin_exp[i]));
            str_temp = origin_exp.substr(temp, i - temp);
            if(CHARACTER.find(str_temp)!=CHARACTER.end()){
                if(!exp.empty() && CHARACTER.at(str_temp).operand==1 && exp.rbegin()->type==0){//右结合单目运算符如果在数字之后，抛出异常
                    throw std::runtime_error(ExpressionError::ILLEGAL_CHARACTER_ERROR);
                }
                exp.push_back(CHARACTER.at(str_temp));
            }
            else{
                throw std::runtime_error(ExpressionError::ILLEGAL_CHARACTER_ERROR);
            }
        }
        else{
            throw std::runtime_error(ExpressionError::ILLEGAL_CHARACTER_ERROR);
        }
    }
    return true;
}

//括号匹配检测
void Expression::BracketPreprocessing() {
    SimStack<int> bracket;
    for(const auto& i : exp){
        if(i.c == "("){  //遇到左括号入栈数字1
            bracket.push(1);
        }
        else if(i.c == ")" && !bracket.isEmpty()){ //右括号出栈
            bracket.pop();
        }
    }
    if (!bracket.isEmpty()) throw std::runtime_error(ExpressionError::BRACKET_ERROR); //栈不为空则括号不匹配
}

//负号处理
void Expression::NegativePreprocessing(){
    for(auto i = exp.begin(); i != exp.end(); ++i)
    {
        //如果负号在首位，在负号前添加数字0
        if ((*i).c == "-"){
            if (i == exp.begin()){
                i = exp.insert(i, CHARACTER.at("0"));
            }
            else{
                //如果负号前为括号，在负号前添加数字0
                --i;
                if ((*i).priority >0){
                    ++i;
                    i = exp.insert(i,CHARACTER.at("0"));
                }
                ++i;
            }
        }
    }
}

//转换为逆波兰表达式，并进行计算
void Expression::TransToPostfix() {
    try{
        for (auto &i : exp)
        {
            //如果当前元素为数值，压入数值栈
            if (i.type == 0)
                num.push(stold(i.c));
            //如果当前元素为运算符，比较其与运算符栈顶元素的优先级
            else if (i.type == 1)
            {
                /*
                 * 如果小于栈顶运算符优先级、栈不为空、栈顶不为左括号三者同时满足
                 * 不断出栈栈顶运算符直到不满足上述三个条件之一
                 * 并依次对出栈的运算符进行运算
                 * 然后入栈当前运算符
                 */
                if (!op.isEmpty() && i.priority <= op.Top().priority && op.Top().priority<30)
                {
                    do
                    {
                        operation();
                    } while (!op.isEmpty()&&i.priority <= op.Top().priority);
                }
                op.push(i);
            }
            //如果当前运算符为括号
            else if (i.type == 2)
            {
                //如果当前括号为左括号，入栈
                if (i.priority > 0)
                {
                    op.push(i);
                }
                //如果当前括号为右括号，出栈运算符栈直到遇到第一个左括号
                else if (i.priority < 0)
                {
                    while (!op.isEmpty() && op.Top().type != 2)
                    {
                        operation();
                    }
                    if(!op.isEmpty()) op.pop();
                }
            }
            else if (op.isEmpty())
                op.push(i);
        }
        //对运算符栈剩余的运算符依次出栈并进行运算
        while (op.Size() >=1)
        {
            operation();
        }

        if(num.Size() > 1)
        {
            throw std::runtime_error(ExpressionError::MISSING_OPRANDS);
        }
    }catch(...){
        throw;
    }
}

//获取结果
long double Expression::getres() {
    try{
        Check_Split();
        PreProcessing();
        TransToPostfix();
    }catch(std::runtime_error&){
        throw;
    }

    res = num.Top();  //数字栈中最后一个数即为结果
    std::cout<<std::setprecision(10);//设置显示小数位
    return res;
}

//计算
void Expression::operation() {
    //单目运算符计算
    if (op.Top().operand==1){
        long double num1;
            calc(op.Top(),num1);
    }
    //双目运算符计算
    else if(op.Top().operand==2){
        long double num1,num2;
            calc(op.Top(),num1,num2);
    }
    op.pop();
}

//单目运算符计算
void Expression::calc(character op, long double &num1) {
    if(num.isEmpty()){
        throw std::runtime_error(ExpressionError::MISSING_OPRANDS);
    }
    else{
        num1 = num.Top();//取操作数栈顶元素
        num.pop();
    }
    //运算结束将结果压入栈
    if(op.c=="!") num.push(math.factorial(num1));
    else if(op.c=="sin") num.push(math.sin(num1));
    else if(op.c=="cos") num.push(math.cos(num1));
    else if(op.c=="tan") num.push(math.tan(num1));
    else if(op.c=="arcsin") num.push(math.arcsin(num1));
    else if(op.c=="arccos") num.push(math.arccos(num1));
    else if(op.c=="arctan") num.push(math.arctan(num1));
    else if(op.c=="lg") num.push(math.lg(num1));
    else if(op.c=="ln") num.push(math.ln(num1));
}

//双目运算符计算
void Expression::calc(character op, long double &num1, long double &num2) {
    //取操作数栈顶前两个元素
    if(num.isEmpty()){
        throw std::runtime_error(ExpressionError::MISSING_OPRANDS);
    }
    else{
        num1 = num.Top();
        num.pop();
    }
    if(num.isEmpty()){
        throw std::runtime_error(ExpressionError::MISSING_OPRANDS);
    }
    else{
        num2 = num.Top();
        num.pop();
    }
    //运算结束将结果压入栈
    if(op.c=="+") num.push(math.add(num1,num2));
    else if(op.c=="-") num.push(math.subtract(num2,num1));
    else if(op.c=="*") num.push(math.multiply(num1,num2));
    else if(op.c=="/") num.push(math.divide(num2,num1));
    else if(op.c=="%") num.push(math.mod(num2,num1));
    else if(op.c=="^") num.push(math.pow(num2,num1));
    else if(op.c=="#") num.push(math.root(num1,num2));
}









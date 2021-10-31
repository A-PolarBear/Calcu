//
// Created by HP on 2021/10/25.
//

#ifndef MAIN_CPP_OPERAND_H
#define MAIN_CPP_OPERAND_H

#include <map>
#include <string>

#define PI "3.1415926535897"
#define E "2.7182818284590"

struct character{
    int type; //字符种类，0为数字、1为运算符、2为括号
    int priority;//运算符优先级，数字为0，加减为1，乘除为2，乘方开方为3，阶乘为4，三角运算为11
    int operand;//判断单目或双目，单目运算符为1，双目运算符为2
    std::string c;
};

const std::map<std::string,character> CHARACTER{
    {"0", character{0,0,0,"0"}},
    {"1", character{0,0,0,"1"}},
    {"2", character{0,0,0,"2"}},
    {"3", character{0,0,0,"3"}},
    {"4", character{0,0,0,"4"}},
    {"5", character{0,0,0,"5"}},
    {"6", character{0,0,0,"6"}},
    {"7", character{0,0,0,"7"}},
    {"8", character{0,0,0,"8"}},
    {"9", character{0,0,0,"9"}},
    {".", character{0,0,0,"."}},
    {"e", character{0,0,0,"E"}},
    {"PI",character{0,0,0,"PI"}},

    {"+", character{1,1,2,"+"}},
    {"-", character{1,1,2,"-"}},
    {"*", character{1,2,2,"*"}},
    {"/", character{1,2,2,"/"}},


    {"%", character{1,2,2,"%"}},
    {"^", character{1,3,2,"^"}},
    {"#", character{1,3,2,"#"}},
    {"!", character{1,4,1,"!"}},

    {"sin", character{1,11,1,"sin"}},
    {"cos", character{1,11,1,"cos"}},
    {"tan", character{1,11,1,"tan"}},
    {"arcsin", character{1,11,1,"arcsin"}},
    {"arccos", character{1,11,1,"arccos"}},
    {"arctan", character{1,11,1,"arctan"}},
    {"lg", character{1,11,1,"lg"}},
    {"ln", character{1,11,1,"ln"}},

    {"(", character{2,30,0,"("}},
    {")", character{2,-1,0,")"}},
};

#endif //MAIN_CPP_OPERAND_H

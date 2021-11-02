//
// Created by HP on 2021/10/26.
//
#include "MathProcess.h"
#include "Operand.h"

MathProcess::MathProcess() {

};

MathProcess::~MathProcess(){

};

long double MathProcess::add(const long double &num1, const long double &num2) const {
    return num1 + num2;
}

long double MathProcess::subtract(const long double &num1, const long double &num2) const {
    return num1 - num2;
}

long double MathProcess::multiply(const long double &num1, const long double &num2) const {
    return num1 * num2;
}

long double MathProcess::divide(const long double &num1, const long double &num2) const {
    if(std::abs(num2) > 0 ){ //除数不为零
        return num1 / num2;
    }
    throw std::runtime_error(MathError::DIVIDED_BY_ZERO);
}

long double MathProcess::mod(const long double &num1, const long double &num2) const {
    if(std::abs(num1 - static_cast<int>(num1))>1e-8||std::abs(num2 - static_cast<int>(num2))>1e-8){ //取余必须为整数
        throw std::runtime_error(MathError::MOD_NUM_NOT_INT);
    }
    if(std::abs(num2) < 1e-8){ //除数为零
        throw std::runtime_error(MathError::DIVIDED_BY_ZERO);
    }
    return static_cast<int>(num1) % static_cast<int>(num2);
}

long double MathProcess::pow(const long double &num1, const long double &num2) const {
    if(std::abs(num1)<1e-8){
        if(num2<0){
             throw std::runtime_error(MathError::DIVIDED_BY_ZERO);
        }
    }
    return std::pow(num1,num2);
}

long double MathProcess::root(const long double &num1, const long double &num2) const {
    if(num1<0){//被开方数是负数的情况
        if(std::abs(num2 - static_cast<int>(num2))<1e-8){ //如果开方数为整数
            if(static_cast<int>(num2)%2==0){ //开方数为偶数，则输出错误
                throw std::runtime_error(MathError::SQUARE_ERROR);
            }
            else{
                return -std::pow(-num1,1/num2); //针对负数的奇数次方根
            }
        }
        else{
            throw std::runtime_error(MathError::SQUARE_ERROR);
        }
    }
    return std::pow(num1,1/num2);
}

long MathProcess::factorial(const long double &num1) const {
    if(std::abs(num1 - static_cast<int>(num1))>1e-8||num1<0||num1>15){ //阶乘数必须为整数且小于15
        throw std::runtime_error(MathError::FACTORIAL_ERROR);
    }
    else{
        long res = 1;
        long i = 1;
        for(;i<=static_cast<long>(num1);i++){
            res *=i;
        }
        return res;
    }
}

long double MathProcess::sin(const long double &num1) const {
    long double temp =num1*(std::stold(PI))/180; //角度值转换弧度制
    return std::sin(temp);
}

long double MathProcess::cos(const long double &num1) const {
    long double temp =num1*(std::stold(PI))/180;
    return std::cos(temp);
}

long double MathProcess::tan(const long double &num1) const {
    long double angle = num1;
    int i_angle = static_cast<int>(num1);
    if (angle - i_angle <= 1e-8 && (i_angle + 90) % 180 == 0)    //正切值不为kπ+π/2
        throw std::runtime_error(MathError::TAN_ERROR);
    angle = num1*(std::stold(PI))/180;
    return std::tan(angle);
}

long double MathProcess::arcsin(const long double &num1) const {
    if(std::abs(num1)>1){ //反正弦函数为-1到1
        throw std::runtime_error(MathError::ARC_ERROR);
    }
    return std::asin(num1);
}

long double MathProcess::arccos(const long double &num1) const {
    if(std::abs(num1)>1){ //反余弦函数为-1到1
        throw std::runtime_error(MathError::ARC_ERROR);
    }
    return std::acos(num1);
}

long double MathProcess::arctan(const long double &num1) const {
    return std::atan(num1);
}

long double MathProcess::lg(const long double &num1) const {
    if(num1<=0){ //对数操作数小于零
        throw std::runtime_error(MathError::LOG_ERROR);
    }
    return std::log10(num1);
}

long double MathProcess::ln(const long double &num1) const {
    if(num1<=0){ //对数操作数小于零
        throw std::runtime_error(MathError::LOG_ERROR);
    }
    return std::log(num1);
}










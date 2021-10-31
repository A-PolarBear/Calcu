//
// Created by HP on 2021/10/26.
//

#ifndef MAIN_CPP_MATHPROCESS_H
#define MAIN_CPP_MATHPROCESS_H

#include <string>
#include <cmath>
#include <stdexcept>

namespace MathError{
    const std::string DIVIDED_BY_ZERO="Divided by zero";//除数为零
    const std::string MOD_NUM_NOT_INT="Mod by non-int";//取余不为整数
    const std::string SQUARE_ERROR="Squared Error";//开方出错
    const std::string FACTORIAL_ERROR="Factorial Error";//阶乘出错
    const std::string TAN_ERROR="Tangent Error";//正切出错
    const std::string ARC_ERROR="Arc Error";//反三角出错
    const std::string LOG_ERROR="Log Error";//对数出错
}


class MathProcess {
public:
    MathProcess();
    ~MathProcess();
    long double add(const long double &num1, const long double &num2) const;
    //减法运算
    long double subtract(const long double &num1, const long double &num2) const;
    //乘法运算
    long double multiply(const long double &num1, const long double &num2) const;
    //除法运算
    long double divide(const long double &num1, const long double &num2) const;
    //模运算
    long double mod(const long double &num1, const long double &num2) const;
    //乘方运算
    long double pow(const long double &num1, const long double &num2) const;
    //开方运算
    long double root(const long double &num1, const long double &num2) const;
    //阶乘运算
    long factorial(const long double &num1) const;
    //正弦运算，num1为角度
    long double sin(const long double &num1) const;
    //余弦运算，num1为角度
    long double cos(const long double &num1) const;
    //正切运算，num1为角度
    long double tan(const long double &num1) const;
    //反正弦运算，返回值为弧度
    long double arcsin(const long double &num1) const;
    //反余弦运算，返回值为弧度
    long double arccos(const long double &num1) const;
    //反正切运算，返回值为弧度
    long double arctan(const long double &num1) const;
    //常用对数，底数为10
    long double lg(const long double &num1) const;
    //自然对数，底数为e
    long double ln(const long double &num1) const;

};


#endif //MAIN_CPP_MATHPROCESS_H

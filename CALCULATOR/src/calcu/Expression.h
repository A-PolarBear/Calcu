//
// Created by HP on 2021/10/24.
//

#ifndef MAIN_CPP_EXPRESSION_H
#define MAIN_CPP_EXPRESSION_H

#include <map>
#include <list>
#include <string>
#include <iomanip>
#include <iostream>
#include "MathProcess.h"
#include "SimStack.hpp"
#include "Operand.h"

namespace ExpressionError {
    const std::string ILLEGAL_CHARACTER_ERROR = "Illegal Character ";//非法字符
    const std::string BRACKET_ERROR = "Illegal Bracket fit ";//括号不匹配
    const std::string MISSING_OPRANDS = "Missing Operands ";//缺少操作数
}

class Expression {
private:
    std::string origin_exp;//原始表达式
    std::list<character> exp;//分离后的表达式
    SimStack<character> op;//运算符栈
    SimStack<long double> num;//操作数栈
    MathProcess math;//数学运算
    long double res = 0;//结果


    bool Check_Split();//表达式分析与分离运算符和操作数单元
    void NegativePreprocessing();//单目负识别与处理
    void BracketPreprocessing();//括号匹配检测
    void PreProcessing();//预处理
    void operation();//运算
    void TransToPostfix();//转换成逆波兰表达式
    void calc(character op, long double &num1);//单目运算符计算
    void calc(character op, long double &num1, long double &num2);//双目运算符计算
public:
    explicit Expression(std::string str);
    ~ Expression();
    long double getres();//获取结果
};


#endif //MAIN_CPP_EXPRESSION_H

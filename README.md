# Calcu
## 项目内容
CalcuX计算器，该计算器可实现加减乘除、单目负、开方乘方、求余、三角函数、反三角函数、自然对数与常用对数、阶乘功能的实现
## 目录结构
````
│  README.md
│
└─CALCULATOR
    │  Calcu_v1.2.exe 计算器可执行文件
    │  README.md 
    │
    └─src  Qt相关文件以及核心功能
        |  Calcu.pro
        │  Calcu.pro.user
        │  icon.qrc
        │  main.cpp
        │  mainwindow.cpp
        │  mainwindow.h
        │  mainwindow.ui
        │  Retroville-NC-1.ttf
        │  scu.ico
        │
        ├─calcu 计算器核心功能源文件
        │      Expression.cpp 表达式处理
        │      Expression.h
        │      MathProcess.cpp 数学计算
        │      MathProcess.h
        │      Operand.h 运算符优先级定义
        │      SimStack.hpp 数组模拟栈实现
        │
        └─icon
````

## 如何构建
````

````
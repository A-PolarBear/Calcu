# Calcu
## 项目内容  
CalcuX计算器，该计算器可实现加减乘除、单目负、开方乘方、求余、三角函数、反三角函数、自然对数与常用对数、阶乘功能的实现
## 目录结构
````
│  Calcu_v1.2.exe  可执行文件
│  README.md 
│
└─src Qt相关源文件以及核心代码
    │  Calcu.pro
    │  Calcu.pro.user
    │  icon.qrc
    │  main.cpp
    │  mainwindow.cpp
    │  mainwindow.h
    │  mainwindow.ui
    │  Retroville-NC-1.ttf
    │  scu.ico
    │
    ├─build 项目构建文件夹
    │
    ├─calcu 计算器核心功能
    │      Expression.cpp 表达式处理类
    │      Expression.h
    │      MathProcess.cpp 数学处理类
    │      MathProcess.h
    │      Operand.h 运算符定义类
    │      SimStack.hpp 数组模拟栈类
    │
    └─icon
````

## 编译安装
+ 依赖：qmake >=3.1  
  windows下编译安装:

````
cd src
cd build
qmake
mingw32-make
````
将release下的exe文件放置在build根目录下，即可运行

## 使用说明
        “#”表示开方，示例：2#4，表示4的二次方根
	    “E”表示自然对数，“e”表示科学记数法，注意区分大小写
	    “PI”表示圆周率
        三角函数全部以角度制输入   
	    方向键下↓为换行，可实现输入多行表达式同时求取结果
        Esc键可清空输入内容
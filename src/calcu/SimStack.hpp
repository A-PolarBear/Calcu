//
// Created by HP on 2021/10/19.
//

#ifndef CALCULATOR_SIMSTACK_H
#define CALCULATOR_SIMSTACK_H

#include<string>
#include <iomanip>

namespace SimStackError{
    const std::string STACK_IS_EMPTY="Stack is empty"; //栈为空报错
    const std::string MALLOCATE_FAILED ="Mallocate failed";//栈分配内存错误
}


template <class T> class SimStack {
private:
    size_t length;//栈的大小
    size_t capacity;//栈的容量
    T *ptr;//指针
    int top = -1;

    void Expand();//容量不够，动态扩展
public:
    SimStack();
    ~SimStack();

    void push(const T&);
    void pop();
    T &Top() const;
    bool isEmpty() const;
    size_t Size();
};

template <class T>
SimStack<T>::SimStack() {
    capacity=10;
    length=0;
    ptr = new T[capacity];
    if (ptr == nullptr)
    {
        throw std::runtime_error(SimStackError::MALLOCATE_FAILED);
    }
}

template <class T>
SimStack<T>::~SimStack<T>() {
    if(ptr!= nullptr){
        delete[] ptr;
    }
}

//压栈
template <class T>
void SimStack<T>::push(const T &it) {
    if(top == capacity-1){//容量不够，动态扩展
        Expand();
    }
    length++;
    ptr[++top]= it;

}

//出栈
template <class T>
void SimStack<T>::pop() {
    if(isEmpty()){
        throw std::runtime_error(SimStackError::STACK_IS_EMPTY);
    }
    else{
        length--;
        ptr[top--].~T();
    }
}

//获取栈顶元素
template <class T>
T & SimStack<T>::Top() const {
    if(isEmpty()){
        throw std::runtime_error(SimStackError::STACK_IS_EMPTY);
    }
    else{
        return ptr[top];
    }
}

//判断栈是否为空，为空返回true
template <class T>
bool SimStack<T>::isEmpty() const {
    if(top==-1){
        return true;
    }
    else{
        return false;
    }
}

//获取栈的大小
template <class T>
size_t SimStack<T>::Size() {
    return length;
}

//栈的动态扩容
template <class T>
void SimStack<T>::Expand(){
    T *temp = new T[2*capacity];//每次两倍扩容
    if(temp == nullptr){
        throw std::runtime_error(SimStackError::MALLOCATE_FAILED);
    }
    std::copy(ptr,ptr+capacity,temp);
    capacity*=2;
    delete[] ptr;
    ptr = temp;
}

#endif //CALCULATOR_SIMSTACK_H

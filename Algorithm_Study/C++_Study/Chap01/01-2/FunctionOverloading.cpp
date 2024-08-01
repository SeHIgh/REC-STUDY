//
//  FunctionOverloading.cpp
//  C++_Study
//
//  Created by 장세현 on 4/5/24.
//

#include "FunctionOverloading.hpp"

FunctionOverloading::FunctionOverloading(){
    MyFunc();
    MyFunc('A');
    MyFunc(12, 13);
}
void FunctionOverloading::MyFunc(void){
    std::cout<<"MyFunc(void) calld"<<std::endl;
}
void FunctionOverloading::MyFunc(char c){
    std::cout<<"MyFunc(char c) calld"<<std::endl;
}
void FunctionOverloading::MyFunc(int a, int b){
    std::cout<<"MyFunc(int a, int b) calld"<<std::endl;
}

//
//  Q01_2_1.cpp
//  C++_Study
//
//  Created by 장세현 on 4/5/24.
//

#include "Q01_2_1.hpp"

SWAP::SWAP(){
    int num1=20, num2=30;
    swap(&num1, &num2);
    std::cout<<num1<<' '<<num2<<std::endl;
    char ch1='A', ch2='Z';
    swap(&ch1, &ch2);
    std::cout<<ch1<<' '<<ch2<<std::endl;
    double dbl1=1.111, dbl2=5.555;
    swap(&dbl1, &dbl2);
    std::cout<<dbl1<<' '<<dbl2<<std::endl;
}

void SWAP::swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void SWAP::swap(char* a, char* b){
    char tmp = *a;
    *a = *b;
    *b = tmp;
}
void SWAP::swap(double* a, double* b){
    double tmp = *a;
    *a = *b;
    *b = tmp;
}


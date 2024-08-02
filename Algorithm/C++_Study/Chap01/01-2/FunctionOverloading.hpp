//
//  FunctionOverloading.hpp
//  C++_Study
//
//  Created by 장세현 on 4/5/24.
//

#ifndef FunctionOverloading_hpp
#define FunctionOverloading_hpp

class FunctionOverloading{
public:
    ~FunctionOverloading(){}
    FunctionOverloading();
    void MyFunc(void);
    void MyFunc(char c);
    void MyFunc(int a, int b);
};

#include <stdio.h>
#include <iostream>

#endif /* FunctionOverloading_hpp */

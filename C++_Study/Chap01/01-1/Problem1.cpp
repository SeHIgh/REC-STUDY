//
//  Problem1.cpp
//  C++_Study
//
//  Created by 장세현 on 4/5/24.
//

#include "Problem1.hpp"

Problem1::Problem1(){
    int val[5];
    
    for(int i =0;i<5;i++){
        std::cout<<i+1<<"번째 정수 입력: ";
        std::cin>>val[i];
        
    }
    int result = 0;
    
    for(int i =0;i<5;i++)
        result += val[i];
    
    std::cout<<"합계: "<<result<<std::endl;
}

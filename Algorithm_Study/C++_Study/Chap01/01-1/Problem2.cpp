//
//  Problem2.cpp
//  C++_Study
//
//  Created by 장세현 on 4/5/24.
//

#include "Problem2.hpp"

Problem2::Problem2(){
    int salePrice = 0;
    
    while(1){
        int salary = 50;
        
        std::cout<<"판매 금액을 만원 단위로 입력(-1 to end): ";
        std::cin>>salePrice;
        
        if(salePrice == -1){
            std::cout<<"프로그램을 종료합니다."<<std::endl;
            break;
        }
        else{
            salary += salePrice*0.12;
            std::cout<<"이번 달 급여: "<<salary<<"만원"<<std::endl;
        }
    }
}

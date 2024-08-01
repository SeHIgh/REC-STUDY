//
//  StringIO.cpp
//  C++_Study
//
//  Created by 장세현 on 4/5/24.
//

#include "StringIO.hpp"

StringIO:: StringIO(){
    char name[100];
    char lang[200];
    
    std::cout<<"이름은 무엇입니까?\n";
    std::cin>>name;
    
    std::cout<<"좋아하는 프로그래밍 언어는 무엇입니까?\n";
    std::cin>>lang;
    
    std::cout<<"내 이름은 "<<name<<"입니다."<<std::endl;
    std::cout<<"제일 좋아하는 언어는 "<<lang<<"입니다."<<std::endl;
}

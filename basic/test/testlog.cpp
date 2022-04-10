/*
 * @Author: MomoTori
 * @Date: 2022-04-10 12:00:47
 * @LastEditors: MomoTori
 * @LastEditTime: 2022-04-10 12:07:39
 * @FilePath: /ChattingBot/basic/test/testlog.cpp
 * @Description: 
 * Copyright (c) 2022 by MomoTori, All Rights Reserved. 
 */
#include"../include/log.h"
#include<iostream>
int main()
{
    std::string line;
    log test;
    line="Hello";
    test.push(line,logType::Rob);
    line="How are you";
    test.push(line,logType::Rob);
    line="EL・PSY・KONGROO";
    test.push(line,logType::Rob);
    std::list<logNode> out=test.getList();
    for (auto &&line : out)
    {
        std::cout<<line.str<<std::endl;
    }
    
}


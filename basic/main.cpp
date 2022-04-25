/*
 * @Author: MomoTori
 * @Date: 2022-04-10 11:44:41
 * @LastEditors: MomoTori
 * @LastEditTime: 2022-04-25 19:33:10
 * @FilePath: /ChattingBot/basic/main.cpp
 * @Description: 
 * Copyright (c) 2022 by MomoTori, All Rights Reserved. 
 */
#include<iostream>
#include<string>
#include<vector>
#include"include/analyze.h"
#include"include/log.h"
int main()
{
    log talkLog;
    std::string line;
    while(1)
    {
        std::getline(std::cin,line);
        talkLog.push(line,logType::Customer);
        BotTalk(line,talkLog.getList());
        talkLog.push(line,logType::Rob);
        std::cout<<line<<std::endl;
    }
}


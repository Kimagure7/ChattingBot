/*
 * @Author: MomoTori
 * @Date: 2022-04-10 11:44:41
 * @LastEditors: MomoTori
 * @LastEditTime: 2022-04-10 12:15:38
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
    int n;//输入个数
    std::string line;
    while(1)
    {
        getline(std::cin,line);
        talkLog.push(line,logType::Customer);
        int ret=analyze(line);
        switch (ret)
        {
        case ana::Keyword:
            /* code */;
            break;
        case ana::API:
            /* code */;
            break;
        
        default:
            break;
        }
    }
}


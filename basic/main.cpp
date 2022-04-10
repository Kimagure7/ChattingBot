/*
 * @Author: MomoTori
 * @Date: 2022-04-10 11:44:41
 * @LastEditors: MomoTori
 * @LastEditTime: 2022-04-10 11:44:42
 * @FilePath: /ChattingBot/basic/main.cpp
 * @Description: 
 * Copyright (c) 2022 by MomoTori, All Rights Reserved. 
 */
#include<iostream>
#include<string>
#include<vector>
#include"include/analyze.h"
int main()
{
    std::vector<std::string> log;
    int n;//输入个数
    std::string line;
    while(1)
    {
        getline(std::cin,line);
        log.push_back(line);
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


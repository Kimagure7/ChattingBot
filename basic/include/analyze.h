/*
 * @Author: MomoTori
 * @Date: 2022-04-10 11:34:32
 * @LastEditors: MomoTori
 * @LastEditTime: 2022-04-25 19:34:22
 * @FilePath: /ChattingBot/basic/include/analyze.h
 * @Description: 
 * Copyright (c) 2022 by MomoTori, All Rights Reserved. 
 */

#pragma once
#include<string>

/*
 * @description: 输入用户输入字符串，将输入的string修改为输出的答复，输出分析用户输入得到的回复
 * @param {string}用户输入，std::list<logNode>用于判断用户是否重复输入
 * @return {enum ana}类型判断
 */
void BotTalk(std::string&,std::list<logNode>&);


/**
 * @description: 判断是否是数学表达式
 * @param {string} &s
 * @return {*}
 */
int isMathExpression(const std::string& s);

const std::string Calculate(const std::string& s);

int isKeyword(const std::string& s);

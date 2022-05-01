/*
 * @Author: MomoTori
 * @Date: 2022-04-10 12:16:47
 * @LastEditors: MomoTori
 * @LastEditTime: 2022-04-25 19:33:58
 * @FilePath: /ChattingBot/basic/analyze.cpp
 * @Description:
 * Copyright (c) 2022 by MomoTori, All Rights Reserved.
 */
#include "include/analyze.h"
#include "include/log.h"
#include <array>

const size_t MAXWORD = 20;

std::array<const char const *, MAXWORD> KeyW = { //决定内容的关键词
    "谁",
    "什么",
    "年龄"};

std::array<const char const *, MAXWORD> StruWord = { //决定分支的关键词
    "你",
    "我",
    "?",
    "？"};

std::array<const char const *, MAXWORD> Answ[10] = { //回复
    "不知名美少女\n",
    "永远的十七岁\n",
    "我觉得这些是你自己应该思考的问题，不属于我回答范围。\n"};

void BotTalk(std::string &line, std::list<logNode> &logList)
{
    if (isMathExpression(line))
    {
        line=Calculate(line);
    }
    else if (isKeyword(line))
    {
    }
    else
    {
    }
}

int isMathExpression(const std::string &s)
{
}

const std::string Calculate(const std::string& s)
{
    
}

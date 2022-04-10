/*
 * @Author: MomoTori
 * @Date: 2022-04-10 11:34:32
 * @LastEditors: MomoTori
 * @LastEditTime: 2022-04-10 11:43:40
 * @FilePath: /ChattingBot/basic/include/analyze.h
 * @Description: 
 * Copyright (c) 2022 by MomoTori, All Rights Reserved. 
 */
#include<string>
enum ana{Keyword,API};

/**
 * @description: 输入用户输入字符串，输出分析用户输入得到的回复类型，如 ana::Keyword = 关键词匹配， ana::API = API调用
 * @param {string}用户输入
 * @return {enum ana}类型判断
 */
const enum ana analyze(const std::string&);






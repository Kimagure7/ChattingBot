/*
 * @Author: MomoTori
 * @Date: 2022-04-10 11:52:24
 * @LastEditors: MomoTori
 * @LastEditTime: 2022-04-10 11:58:49
 * @FilePath: /ChattingBot/basic/log.cpp
 * @Description: 
 * Copyright (c) 2022 by MomoTori, All Rights Reserved. 
 */
#include"include/log.h"

logNode::logNode(const std::string & s,enum logType t):type(t),str(s){}

log::log():n(0),logList(std::list<logNode>()){}

void log::push(const std::string & s,enum logType type)
{
    logList.push_front(logNode(s,type));
    n++;    
}

const std::list<logNode>& log::getList(){
    return logList;
}
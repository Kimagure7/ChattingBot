/*
 * @Author: MomoTori
 * @Date: 2022-04-10 11:46:31
 * @LastEditors: MomoTori
 * @LastEditTime: 2022-04-25 19:00:32
 * @FilePath: /ChattingBot/basic/include/log.h
 * 
 * 
 * @Description: 该头文件主要描述存储对话的数据结构log
 * 
 * 
 * Copyright (c) 2022 by MomoTori, All Rights Reserved. 
 */

#pragma once
#include<string>
#include<list>

enum logType{Rob,Customer};

struct logNode
{
    enum logType type; //对话类型（来自用户or机器人）
    std::string str;    //对应内容
    //构造函数
    logNode(const std::string & s,enum logType type);
};



class log
{
private:
   int n;//对话个数
   std::list<logNode> logList;//链表头部为最近的对话
public:
    //构造函数
    log();
    
    //请把bot输出和用户输入的话都push到log里面，以便后面GUI中log回溯
    void push(const std::string & s,enum logType type);

    /**
     * @description: 输出对话log的list
     * @return 对话log的list，是一个list型数据类型，每个单元是logNode类型数据，logNode有两个成员，一个是string为对话内容，另一个是logType为是谁说的话
     */    
    const std::list<logNode>& getList();
};


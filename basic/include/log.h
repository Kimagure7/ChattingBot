/*
 * @Author: MomoTori
 * @Date: 2022-04-10 11:46:31
 * @LastEditors: MomoTori
 * @LastEditTime: 2022-04-10 12:07:08
 * @FilePath: /ChattingBot/basic/include/log.h
 * 
 * 
 * @Description: 该头文件主要描述存储对话的数据结构log
 * 
 * 
 * Copyright (c) 2022 by MomoTori, All Rights Reserved. 
 */
#include<string>
#include<list>

enum logType{Rob,Customer};

struct logNode
{
    enum logType type; //对话类型
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
    //输入内容
    void push(const std::string & s,enum logType type);

    //输出
    const std::list<logNode>& getList();
};


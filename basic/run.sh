#!/bin/bash
###
 # @Author: MomoTori
 # @Date: 2022-04-21 13:40:10
 # @LastEditors: MomoTori
 # @LastEditTime: 2022-04-21 13:40:11
 # @FilePath: /ChattingBot/basic/run.sh
 # @Description: 
 # Copyright (c) 2022 by MomoTori, All Rights Reserved. 
### 
g++ main.cpp log.cpp analyze.cpp -o bin/main
./bin/main
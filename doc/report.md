# ChattingBot 实验报告

- [ChattingBot 实验报告](#chattingbot-实验报告)
  - [组员](#组员)
  - [基于字符串匹配的basic部分](#基于字符串匹配的basic部分)
  - [基于Pytorch的深度学习部分](#基于pytorch的深度学习部分)
  - [基于调用api的api部分](#基于调用api的api部分)
  - [GUI界面](#gui界面)
  - [html界面](#html界面)


## 组员

- 马俊杰 (Mahiru)
- 杨涛 (Momo Tori)
- 殷尘龙
- 赵子毅

## 基于字符串匹配的basic部分

## 基于Pytorch的深度学习部分

## 基于调用api的api部分

本部分基于API图灵机器人，利用requests和json库实现API交互

图灵机器人介绍如下：

[新建标签页 (tuling123.com)](http://tuling123.com/help/h_cent_webapi.jhtml)

核心代码如下：

```python
#
# @Author: Mahiru
# @Date: 2022-04-24 10:16:47
# @LastEditors: Mahiru
# @LastEditTime: 2022-04-24 16:18:25
# @FilePath: /ChattingBot/api/bot.py
# @Description: 
# Copyright (c) 2022 by Mahiru, All Rights Reserved. 
#

import json
import requests
API_URL = 'http://openapi.turingapi.com/openapi/api/v2'
KEY = 'c70f2778ff35474e93cb8b11195030d0'

def chat(text: str, user: str) -> str:
    data = {
        'perception': {
            'inputText': {'text': text}
        },
        'userInfo': {
            'apiKey': KEY, 'userId': user
        }
    }
    raw = requests.post(API_URL,json.dumps(data))
    records = json.loads(raw.text)['results']  # 得到API返回的一条条回复
    # print(records)
    ans = ''  # 最终的结果

    for record in records:
        restype = record['resultType']
        resval = record['values'][restype]
        if restype == 'url' or restype == 'text':
            ans += resval+'\n'
        else:
            pass  # 或许可以加点功能
    return ans


if __name__ == '__main__':
    while True:
        text = input('input message: ')
        print(chat(text, 'me'))

```

讲解已在注释给出，不在赘述

## GUI界面

## html界面

### 前端部分

此部分由组员马俊杰 (Mahiru) 完成

```html
<!DOCTYPE html>
<html>

<head>
    <link href="resource/css.css" rel="stylesheet">
    <!-- <link href="resource/materialdesignicons.min.css" rel="stylesheet"> -->
    <link href="resource/vuetify.min.css" rel="stylesheet">
    <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no, minimal-ui">
</head>

<body>
    <div id="app">
        <v-app>
            <v-main>
                <v-container fluid class="pa-0">
                    <v-row class="text-center">
                        <v-col class="my-12" cols="12">
                            <!-- 标题 -->
                            <h1 class="display-2 font-weight-bold my-6 lime--text text--lighten-5">Chatbot</h1>
                        </v-col>
                    </v-row>
                    <v-row>
                        <v-col cols="3"></v-col>
                        <v-col cols="6" sm="6" justify="center">
                            <v-card class="mx-auto">
                                <v-container>

                                    <!-- 模式选择 -->
                                    <v-select :items="items" v-model="mode" label="Mode"></v-select>

                                    <!-- 文本输入 -->
                                    <v-textarea v-model="msg" clearable clear-icon="mdi-close-circle"
                                        label="Input text here">
                                    </v-textarea>

                                    <!-- 发送按钮 -->
                                    <v-card-actions>
                                        <v-btn color="deep-purple lighten-2" text @click="send">
                                            Send
                                        </v-btn>
                                    </v-card-actions>


                                </v-container>
                            </v-card>
                        </v-col>
                        <v-col cols="3"></v-col>
                    </v-row>

                    <!-- 机器人回复，初始状况下不显示 -->
                    <v-row v-if="show_response">
                        <v-col cols="3"></v-col>
                        <v-col cols="6" sm="6" justify="center">
                            <v-card class="mx-auto">
                                <v-card-text class="pb-0">


                                    <!-- 机器人回复 -->
                                    <p class="subtitle-1">
                                        {{response}}
                                    </p>

                                </v-card-text>
                                <br>
                            </v-card>
                        </v-col>
                        <v-col cols="3"></v-col>
                    </v-row>
                </v-container>
            </v-main>
        </v-app>
    </div>

    <style>
        /* 设置背景 */
        #app {
            background: url('resource/bg2.png') no-repeat center;
            background-size: cover;
        }
    </style>
    <!-- 引用的代码 -->
    <script src="resource/jquery.min.js"></script>
    <script src="resource/vue.js"></script>
    <script src="resource/vuetify.js"></script>


    <script>
        new Vue({
            el: '#app',
            vuetify: new Vuetify({
                theme: { dark: true },//设置黑色主题
            }),

            data: () => ({
                items: ["Default", "NeuralNetwork", "API"],//模式
                mode: "Default",//所选的模式，默认为Default
                msg: "Hello",//用户输入，默认为Hello
                response: "",//后台返回的数据
                show_response: false,//是否显示机器人回复的那个组件，用户还没发信息的时候就先不显示
            }),
            methods: {
                send() {//发消息
                    this.show_response = true//开始显示机器人的回复
                    var that = this
                    $.get("/chat", { msg: this.msg, mode: this.mode }).then(data => that.response = data)
                    console.log(this.mode)
                    console.log(this.msg)
                },
            },
        })
    </script>
</body>

</html>
```

引用的css等代码在resources文件夹中，代码讲解在注释给出

### 后端部分

```python
#
# @Author: Mahiru
# @Date: 2022-05-20
# @LastEditors: Mahiru
# @LastEditTime: 2022-05-24 
# @FilePath: /ChattingBot/html/backend.py
# @Description: 
# Copyright (c) 2022 by Mahiru, All Rights Reserved. 
#

from flask import Flask,request,send_from_directory
import bot
import Ctalk, Etalk

with open('index.html','r',encoding='utf-8') as f:
    pagetext=f.read()
app=Flask(__name__)

#handle webpage
@app.route('/')
def webpage():
    return pagetext

#handle response
@app.route('/chat',methods=['GET'])
def chat():
    mode=str(request.args['mode'])
    msg=str(request.args['msg'])
    print(f'mode {mode}')
    print(f'message:\n{msg}')
    if mode=='Default':
        # 默认模式为英文深度学习
        reply=default(msg)
    elif mode=='NeuralNetwork':
        reply=nn(msg)
    else:
        reply=api(msg)
    # 后端打印回复用于debug
    print(f'reply:\n{reply}')
    return reply

# handle requested resources e.g. images, js files
@app.route('/resource/<path:path>')
def send_report(path):
    return send_from_directory('resource', path)

# handle default
def default(msg):
    #英文深度学习
    return Etalk.talk(msg)

# handle neural network
def nn(msg):
    #中文深度学习
    return Ctalk.talk(msg)

#handle api
def api(msg):
    return bot.chat(msg,'me')



if __name__=='__main__':
    app.run(host='127.0.0.1',port=8765)
    print('running on 127.0.0.1:8765')
```

启动后端后会在本地8765端口运行，用flask库实现前后端交互，讲解已在注释给出
# ChattingBot 实验报告

- [ChattingBot 实验报告](#chattingbot-实验报告)
  - [组员](#组员)
  - [基于字符串匹配的basic部分](#基于字符串匹配的basic部分)
  - [基于Pytorch的深度学习部分](#基于pytorch的深度学习部分)
  - [基于调用api的api部分](#基于调用api的api部分)
  - [GUI界面](#gui界面)
    - [按钮位置定义](#按钮位置定义)
    - [菜单栏定义](#菜单栏定义)
    - [按钮名字、提示符、快捷键定义](#按钮名字提示符快捷键定义)
    - [按钮事件定义](#按钮事件定义)
    - [其他修改](#其他修改)
  - [html界面](#html界面)
    - [前端部分](#前端部分)
    - [后端部分](#后端部分)


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

基于Pyqt6开发

![界面](./image/pyqt%E7%95%8C%E9%9D%A2.png)

包含两个按钮、发送框、接受框、模式选择菜单

### 按钮位置定义

如代码所示 分别定义各个按钮和文本框位置

line为两个对话框中间的分割线

同时设置提示消息（鼠标放置于按钮上时的提示信息）以及快捷键

```py
# 主窗口
        ChattingBot.setObjectName("ChattingBot")
        ChattingBot.resize(800, 600)
        self.centralwidget = QtWidgets.QWidget(ChattingBot)
        self.centralwidget.setObjectName("centralwidget")

        self.Enter = QtWidgets.QPushButton(self.centralwidget)
        self.Enter.setGeometry(QtCore.QRect(457, 440, 81, 24))
        self.Enter.setObjectName("Enter")
        self.Enter.setStatusTip('快捷键为Ctrl+Enter')
        self.OutputText = QtWidgets.QTextBrowser(self.centralwidget)
        self.OutputText.setGeometry(QtCore.QRect(71, 41, 471, 291))
        self.OutputText.setObjectName("OutputText")

        self.InputText = QtWidgets.QTextEdit(self.centralwidget)
        self.InputText.setGeometry(QtCore.QRect(70, 350, 471, 81))
        self.InputText.setObjectName("InputText")

        self.line = QtWidgets.QFrame(self.centralwidget)
        self.line.setGeometry(QtCore.QRect(70, 330, 471, 21))
        self.line.setFrameShape(QtWidgets.QFrame.Shape.HLine)
        self.line.setFrameShadow(QtWidgets.QFrame.Shadow.Sunken)
        self.line.setObjectName("line")

        self.close = QtWidgets.QPushButton(self.centralwidget)
        self.close.setGeometry(QtCore.QRect(370, 440, 75, 24))
        self.close.setObjectName("close")
        self.close.setStatusTip('快捷键为Ctrl+Q')

        ChattingBot.setCentralWidget(self.centralwidget)
```

### 菜单栏定义

1. 0级和1级菜单

```py
# 模式选择组件

        self.menubar = QtWidgets.QMenuBar(ChattingBot)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 800, 22))
        self.menubar.setObjectName("menubar")
        self.options = QtWidgets.QMenu(self.menubar)
        self.options.setObjectName("settings")
        self.mode = QtWidgets.QMenu(self.options)
        self.mode.setObjectName("mode")
        ChattingBot.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(ChattingBot)
        self.statusbar.setObjectName("statusbar")
        ChattingBot.setStatusBar(self.statusbar)
```

2. 2级菜单

```py
# 三大模式
        # 默认是dl模式
        self.basic = QtGui.QAction(ChattingBot)
        self.basic.setCheckable(True)
        self.basic.setChecked(False)
        self.basic.setObjectName("basic")
        self.basic.setStatusTip('基于字符串匹配实现')
        self.DeepLearning = QtGui.QAction(ChattingBot)
        self.DeepLearning.setCheckable(True)
        self.DeepLearning.setChecked(True)
        self.DeepLearning.setObjectName("DeepLearning")
        self.DeepLearning.setStatusTip('基于Pytorch实现')
        self.api = QtGui.QAction(ChattingBot)
        self.api.setCheckable(True)
        self.api.setChecked(False)
        self.api.setObjectName("API")
        self.mode.addAction(self.basic)
        self.mode.addAction(self.DeepLearning)
        self.mode.addAction(self.api)
        self.options.addAction(self.mode.menuAction())
        self.menubar.addAction(self.options.menuAction())
```

### 按钮名字、提示符、快捷键定义

1. setText为按钮上显示的字符串
2. setTitle为菜单上显示的字符串
3. setToolTip为鼠标放在模式选择上的时候，左下角出现的提示信息（按钮的提示在前面）
```py
def retranslateUi(self, ChattingBot):
        """负责标签名字"""
        _translate = QtCore.QCoreApplication.translate
        ChattingBot.setWindowTitle(_translate("ChattingBot", "MainWindow"))
        self.Enter.setText(_translate("ChattingBot", "发送"))
        self.Enter.setShortcut(_translate("ChattingBot", "Ctrl+Return"))
        self.close.setText(_translate("ChattingBot", "关闭"))
        self.close.setShortcut(_translate("ChattingBot", "Ctrl+Q"))
        self.options.setTitle(_translate("ChattingBot", "settings"))
        self.mode.setTitle(_translate("ChattingBot", "mode"))
        self.basic.setText(_translate("ChattingBot", "basic"))
        self.basic.setToolTip(_translate("ChattingBot", "基于字符串匹配实现"))
        self.DeepLearning.setText(_translate("ChattingBot", "DeepLearning"))
        self.DeepLearning.setToolTip(_translate("ChattingBot", "基于Pytorch实现"))
        self.api.setText(_translate("ChattingBot", "api"))
        self.api.setToolTip(_translate("ChattingBot", "基于API调用实现"))
```

### 按钮事件定义


需要注意 传递参数必须使用lambda隐式函数传递 不然无法成功传递
```py
 self.retranslateUi(ChattingBot)
        # 按钮事件定义
        # self.Enter.clicked['bool'].connect(lambda: self.buttonClicked(ChattingBot))
        self.Enter.clicked['bool'].connect(self.chatting)
        self.Enter.clicked['bool'].connect(self.InputText.clear)
        self.close.clicked['bool'].connect(ChattingBot.close)  # 直接关闭当前窗口
        # 按下后保证只有一个按钮亮起
        self.basic.triggered.connect(lambda: self.mode_select(ChattingBot))
        self.DeepLearning.triggered.connect(lambda: self.mode_select(ChattingBot))
        self.api.triggered.connect(lambda: self.mode_select(ChattingBot))
        # QtCore.QMetaObject.connectSlotsByName(ChattingBot)
```

### 其他修改

由于GUI界面为最终对话的界面 所以需要做出一些修改

- 确保只有一个模式启用
  ```py
  def mode_select(self, ChattingBot):
        """选择模式时确保只有一个模式在使用"""
        sender = ChattingBot.sender()
        if sender == self.basic:
            if not self.basic.isChecked():  # 把唯一一个亮着的按了下去
                self.basic.setChecked(True)
            else:
                self.DeepLearning.setChecked(False)
                self.api.setChecked(False)
        if sender == self.DeepLearning:
            if not self.DeepLearning.isChecked():  # 把唯一一个亮着的按了下去
                self.DeepLearning.setChecked(True)
            else:
                self.basic.setChecked(False)
                self.api.setChecked(False)
        if sender == self.api:
            if not self.api.isChecked():  # 把唯一一个亮着的按了下去
                self.api.setChecked(True)
            else:
                self.basic.setChecked(False)
                self.DeepLearning.setChecked(False)
  ```

- 状态获取
  ```py
  def getState(self) -> int:
        if self.api.isChecked():
            return 3
        if self.DeepLearning.isChecked():
            return 2
        if self.basic.isChecked():
            return 1
  ```

- 对话
  ```py
  def chatting(self):
        """作用是发送input的文本到其他模块"""
        content = self.InputText.toPlainText()
        # TODO： 接入其他模块以完成最终通信
        state = self.getState()
        result = ''
        if state == 1:
            self.OutputText.setText('由于编码问题 该模块不可用')
            return
        if state == 2:
            if is_en(content[0]):
                result = DLEChat(content)
            else:
                result = DLCChat(content)
        if state == 3:
            result = apiChat(content)

        ans = 'You:' + content + '\nBot:' + result  # ans为最终回复
        self.OutputText.setText(ans)

  def apiChat(x: str) -> str:
      return bot.chat(x, 'me')


  def DLEChat(x: str) -> str:
      """英文版深度学习"""
      return Etalk.talk(x)


  def DLCChat(x: str) -> str:
      """中文版深度学习"""
      return Ctalk.talk(x)


  def is_en(w) -> bool:
      if 'a' <= w <= 'z' or 'A' <= w <= 'Z':
          return True
      else:
          return False
  ```

效果展示:
![聊天结果](./image/%E8%81%8A%E5%A4%A9%E7%BB%93%E6%9E%9C1.png)

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

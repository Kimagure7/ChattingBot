# ChattingBot ʵ�鱨��

- [ChattingBot ʵ�鱨��](#chattingbot-ʵ�鱨��)
  - [��Ա](#��Ա)
  - [�����ַ���ƥ���basic����](#�����ַ���ƥ���basic����)
  - [����Pytorch�����ѧϰ����](#����pytorch�����ѧϰ����)
  - [���ڵ���api��api����](#���ڵ���api��api����)
  - [GUI����](#gui����)
  - [html����](#html����)


## ��Ա

- ���� (Mahiru)
- ���� (Momo Tori)
- ����
- ������

## �����ַ���ƥ���basic����

## ����Pytorch�����ѧϰ����

## ���ڵ���api��api����

�����ֻ���APIͼ������ˣ�����requests��json��ʵ��API����

ͼ������˽������£�

[�½���ǩҳ (tuling123.com)](http://tuling123.com/help/h_cent_webapi.jhtml)

���Ĵ������£�

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
    records = json.loads(raw.text)['results']  # �õ�API���ص�һ�����ظ�
    # print(records)
    ans = ''  # ���յĽ��

    for record in records:
        restype = record['resultType']
        resval = record['values'][restype]
        if restype == 'url' or restype == 'text':
            ans += resval+'\n'
        else:
            pass  # ������Լӵ㹦��
    return ans


if __name__ == '__main__':
    while True:
        text = input('input message: ')
        print(chat(text, 'me'))

```

��������ע�͸���������׸��

## GUI����

## html����

### ǰ�˲���

�˲�������Ա���� (Mahiru) ���

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
                            <!-- ���� -->
                            <h1 class="display-2 font-weight-bold my-6 lime--text text--lighten-5">Chatbot</h1>
                        </v-col>
                    </v-row>
                    <v-row>
                        <v-col cols="3"></v-col>
                        <v-col cols="6" sm="6" justify="center">
                            <v-card class="mx-auto">
                                <v-container>

                                    <!-- ģʽѡ�� -->
                                    <v-select :items="items" v-model="mode" label="Mode"></v-select>

                                    <!-- �ı����� -->
                                    <v-textarea v-model="msg" clearable clear-icon="mdi-close-circle"
                                        label="Input text here">
                                    </v-textarea>

                                    <!-- ���Ͱ�ť -->
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

                    <!-- �����˻ظ�����ʼ״���²���ʾ -->
                    <v-row v-if="show_response">
                        <v-col cols="3"></v-col>
                        <v-col cols="6" sm="6" justify="center">
                            <v-card class="mx-auto">
                                <v-card-text class="pb-0">


                                    <!-- �����˻ظ� -->
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
        /* ���ñ��� */
        #app {
            background: url('resource/bg2.png') no-repeat center;
            background-size: cover;
        }
    </style>
    <!-- ���õĴ��� -->
    <script src="resource/jquery.min.js"></script>
    <script src="resource/vue.js"></script>
    <script src="resource/vuetify.js"></script>


    <script>
        new Vue({
            el: '#app',
            vuetify: new Vuetify({
                theme: { dark: true },//���ú�ɫ����
            }),

            data: () => ({
                items: ["Default", "NeuralNetwork", "API"],//ģʽ
                mode: "Default",//��ѡ��ģʽ��Ĭ��ΪDefault
                msg: "Hello",//�û����룬Ĭ��ΪHello
                response: "",//��̨���ص�����
                show_response: false,//�Ƿ���ʾ�����˻ظ����Ǹ�������û���û����Ϣ��ʱ����Ȳ���ʾ
            }),
            methods: {
                send() {//����Ϣ
                    this.show_response = true//��ʼ��ʾ�����˵Ļظ�
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

���õ�css�ȴ�����resources�ļ����У����뽲����ע�͸���

### ��˲���

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
        # Ĭ��ģʽΪӢ�����ѧϰ
        reply=default(msg)
    elif mode=='NeuralNetwork':
        reply=nn(msg)
    else:
        reply=api(msg)
    # ��˴�ӡ�ظ�����debug
    print(f'reply:\n{reply}')
    return reply

# handle requested resources e.g. images, js files
@app.route('/resource/<path:path>')
def send_report(path):
    return send_from_directory('resource', path)

# handle default
def default(msg):
    #Ӣ�����ѧϰ
    return Etalk.talk(msg)

# handle neural network
def nn(msg):
    #�������ѧϰ
    return Ctalk.talk(msg)

#handle api
def api(msg):
    return bot.chat(msg,'me')



if __name__=='__main__':
    app.run(host='127.0.0.1',port=8765)
    print('running on 127.0.0.1:8765')
```

������˺���ڱ���8765�˿����У���flask��ʵ��ǰ��˽�������������ע�͸���
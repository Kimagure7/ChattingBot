# ChattingBot ʵ�鱨��


<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [ChattingBot ʵ�鱨��](#chattingbot-ʵ�鱨��)
  - [��Ա](#��Ա)
  - [�����ַ���ƥ���basic����](#�����ַ���ƥ���basic����)
  - [����Pytorch�����ѧϰ����](#����pytorch�����ѧϰ����)
    - [�˽����ѧϰԭ��Seq2Seqģ��](#�˽����ѧϰԭ��seq2seqģ��)
    - [Ӣ�����������](#Ӣ�����������)
      - [�����](#�����)
      - [ѵ��������](#ѵ��������)
      - [ģ�͹���](#ģ�͹���)
      - [����ѵ������](#����ѵ������)
    - [�������������](#�������������)
      - [�ִ�](#�ִ�)
      - [���ݴ���](#���ݴ���)
    - [��ͬѵ����](#��ͬѵ����)
      - [Ӣ�ĵ�Ӱ�Ի�](#Ӣ�ĵ�Ӱ�Ի�)
      - [��������](#��������)
      - [�Լ������С˵�Ի�](#�Լ������С˵�Ի�)
  - [���ڵ���api��api����](#���ڵ���api��api����)
  - [GUI����](#gui����)
    - [��ťλ�ö���](#��ťλ�ö���)
    - [�˵�������](#�˵�������)
    - [��ť���֡���ʾ������ݼ�����](#��ť������ʾ����ݼ�����)
    - [��ť�¼�����](#��ť�¼�����)
    - [�����޸�](#�����޸�)
  - [html����](#html����)
    - [ǰ�˲���](#ǰ�˲���)
    - [��˲���](#��˲���)

<!-- /code_chunk_output -->



## ��Ա

- ����        (Mahiru)
  - ���htmlǰ����Ƽ���python������
  - ���api����ģ��
- ����          (MomoTori)
    - ʵ��Ӣ�����������
    - ʵ���������������
    - ���Բ�ͬ������ѵ����
- ����
- ������        (Kimagure)
  - �������GUI����
  - �޸�Pytorchģ��ӿ� ʹ���ܱ�GUI����
  - ����ѧϰPytorchԭ��

## �����ַ���ƥ���basic����

## ����Pytorch�����ѧϰ����

### �˽����ѧϰԭ��Seq2Seqģ��

������Ҫͨ��3B1B����Ƶ�������˽����ѧϰԭ��([���ķ���Ƶ��](https://space.bilibili.com/88461692/search/video?keyword=%E5%AD%A6%E4%B9%A0))�������˽������ѧϰ�Ĺ��̴������£�

- ����Ӧ�ó����������ݳ����������ʵ�ģ��
- ���ѵ�����̣����������з��򴫲������²���
- ����ѵ��
- ����ѵ���ɹ�

����������˳��õ�ģ��ΪSeq2Seqģ�ͣ����ɱ䳤��������Ϊ���룬��ʹ�ù̶���С��ģ�ͽ��ɱ䳤��������Ϊ������ء�

### Ӣ�����������

��Ϊ�������ƣ���Ҫ�ο�����Ľ̳���������ˣ�������Ⲣ��һ��������ʵ��ϣ�����̼���

Ӣ�ģ�https://pytorch.org/tutorials/beginner/chatbot_tutorial.html

���ķ��룺https://tanbro.github.io/pytorch-tutorials-notebooks-zhs/beginner/chatbot_tutorial

�ý̳̰��������ݴ���ģ�͹�����ѵ�������Լ�ģ�͵����У����Ķ�����֮�󽫸���ģ��ֿ飬���Եõ� train �� talk �������֣��ֱ��Ӧѵ��ģ�ͺ�����ѵ���õ�ģ��

#### �����

��Ҫ��װCUDA��pytorch�⣨��һ��GPU��

#### ѵ��������

ѵ�����ĸ�ʽΪ��

```
a b c \t e f g
a b c \t e f g
```

ͨ���ո�` `���дʵ����֣�����ͨ��ת�Ʒ���`\t`����������ظ���ÿһ��Ϊһ���ʴ�

�����ļ�����󣬽���һ��`Voc`������ÿ���ʻ���������������ͽ��ʻ�ӳ��Ϊ����ֵ���������ܹ�ת��Ϊ `pytorch` �ܹ������������ʽ

#### ģ�͹���

�̳��еĴ���ģ������

![](https://pytorch.org/tutorials/_images/seq2seq_ts.png)

ͬʱ��`encoder` �� `decoder` �еĵ��� `GUR` ����˫�� `GUR` ������ֱ�ӵ��� `pytorch` �� `nn.GRU` ���ʵ�֣������� `decoder` ��ʹ�á�ע�������ơ������������ֻ��ע�������е�ĳЩ���֣�����������׼ȷ��

![](https://pytorch.org/tutorials/_images/global_attn.png)

#### ����ѵ������

��Ϊ���������������䣬������ʧ������Ҫ������ʧ��������Ӧ������������1��Ԫ�صĸ��������ƶ�

```py
def maskNLLLoss(inp, target, mask):
    nTotal = mask.sum()
    crossEntropy = -torch.log(torch.gather(inp, 1, target.view(-1, 1)).squeeze(1))
    loss = crossEntropy.masked_select(mask).mean()
    loss = loss.to(device)
    return loss, nTotal.item()
```

�ڶ�������ʧ����֮�󣬾Ϳ����� `pytorch` �ĺ������з��򴫲���������

### �������������

#### �ִ�

���ǵ�Ӣ���Դ��ո���дʻ�Ļ��֣����Ҫʵ��������������ˣ���������Ҫ�����ĵĻ���

������Ľ�������ǵ��� `jieba` �������зִʣ����ڴ����м����ո�ʵ��ԭӢ�Ļ����˿ո�ִʵ�Ч��������ʵ��Ϊ

```py
str=' '.join(jieba.cut(s, cut_all=True))
```

#### ���ݴ���

�Դ�С˵�н�ȡ�Ի�Ϊ�����ձ���С˵�Է��� `��` ��Ϊ�Ի��Ŀ�ͷ��Ϊ�˽�ȡ�Ի���Ҫ̽�����ж����� `��` ��ͷ���ĶΣ��������ȡ��������Ϊ `a \t b`����ʽ����������

```py
line1=""
line2=""
lineList=[]

def dataProcessing(fileName):
    with open(fileName,"r",encoding="utf=8") as input:
        while True:
            line1=input.readline()  # ����'\n'
            if line1=="":           
                break               # �ļ�����
            line1=line1.strip()
            if line1=="":
                continue
            if line1[0]=="��":
                line2=input.readline()  # ƥ��ڶ���"��"
                if line2=="":
                    break
                line2=line2.strip()
                if line2=="":
                    continue
                if line2[0]=="��":
                    line1=line1[1:-1]
                    line2=line2[1:-1]
                    lineList.append(line1.strip()+"\t"+line2.strip())

    with open("de"+fileName,"w",encoding="utf=8") as out:
        for line in lineList:
            out.write(line+"\n")
```

֮����� `train.py` ���ļ������ʽ���ַ������һЩϸ�ھͿ��Կ�ʼѵ�����������������

### ��ͬѵ����

#### Ӣ�ĵ�Ӱ�Ի�

ԭ�̳����õ�ѵ���������Կ���������Щ������

![](image/3.png)

#### ��������

������ĳ��������˽���Ⱥ���Ի���Ϊ��������Ч���Ϻ�

�������ȡһЩ�Ƚ������Ļظ�������Ȼ��ǿ���Կ����ظ�����˼���ظ���������Ȼ�ܴ󣬴�����������Լ������������﷨�ľ���

![](image/1.png)

#### �Լ������С˵�Ի�

��Ϊѵ�����󲿷ֽ�ȡ�����С˵���;���Ĺ�ϵ�Ժ�ǿ����͵��������ճ��Ի�����������޷��õ���Ҫ�Ľ�������һظ��Ļ�������ĳЩǰ�������Ժ;����Ժ�ǿ������

![](image/2.png)

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

����Pyqt6����

![����](./image/pyqt%E7%95%8C%E9%9D%A2.png)

����������ť�����Ϳ򡢽��ܿ�ģʽѡ��˵�

### ��ťλ�ö���

�������ʾ �ֱ��������ť���ı���λ��

lineΪ�����Ի����м�ķָ���

ͬʱ������ʾ��Ϣ���������ڰ�ť��ʱ����ʾ��Ϣ���Լ���ݼ�

```py
# ������
        ChattingBot.setObjectName("ChattingBot")
        ChattingBot.resize(800, 600)
        self.centralwidget = QtWidgets.QWidget(ChattingBot)
        self.centralwidget.setObjectName("centralwidget")

        self.Enter = QtWidgets.QPushButton(self.centralwidget)
        self.Enter.setGeometry(QtCore.QRect(457, 440, 81, 24))
        self.Enter.setObjectName("Enter")
        self.Enter.setStatusTip('��ݼ�ΪCtrl+Enter')
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
        self.close.setStatusTip('��ݼ�ΪCtrl+Q')

        ChattingBot.setCentralWidget(self.centralwidget)
```

### �˵�������

1. 0����1���˵�

```py
# ģʽѡ�����

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

2. 2���˵�

```py
# ����ģʽ
        # Ĭ����dlģʽ
        self.basic = QtGui.QAction(ChattingBot)
        self.basic.setCheckable(True)
        self.basic.setChecked(False)
        self.basic.setObjectName("basic")
        self.basic.setStatusTip('�����ַ���ƥ��ʵ��')
        self.DeepLearning = QtGui.QAction(ChattingBot)
        self.DeepLearning.setCheckable(True)
        self.DeepLearning.setChecked(True)
        self.DeepLearning.setObjectName("DeepLearning")
        self.DeepLearning.setStatusTip('����Pytorchʵ��')
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

### ��ť���֡���ʾ������ݼ�����

1. setTextΪ��ť����ʾ���ַ���
2. setTitleΪ�˵�����ʾ���ַ���
3. setToolTipΪ������ģʽѡ���ϵ�ʱ�����½ǳ��ֵ���ʾ��Ϣ����ť����ʾ��ǰ�棩
```py
def retranslateUi(self, ChattingBot):
        """�����ǩ����"""
        _translate = QtCore.QCoreApplication.translate
        ChattingBot.setWindowTitle(_translate("ChattingBot", "MainWindow"))
        self.Enter.setText(_translate("ChattingBot", "����"))
        self.Enter.setShortcut(_translate("ChattingBot", "Ctrl+Return"))
        self.close.setText(_translate("ChattingBot", "�ر�"))
        self.close.setShortcut(_translate("ChattingBot", "Ctrl+Q"))
        self.options.setTitle(_translate("ChattingBot", "settings"))
        self.mode.setTitle(_translate("ChattingBot", "mode"))
        self.basic.setText(_translate("ChattingBot", "basic"))
        self.basic.setToolTip(_translate("ChattingBot", "�����ַ���ƥ��ʵ��"))
        self.DeepLearning.setText(_translate("ChattingBot", "DeepLearning"))
        self.DeepLearning.setToolTip(_translate("ChattingBot", "����Pytorchʵ��"))
        self.api.setText(_translate("ChattingBot", "api"))
        self.api.setToolTip(_translate("ChattingBot", "����API����ʵ��"))
```

### ��ť�¼�����


��Ҫע�� ���ݲ�������ʹ��lambda��ʽ�������� ��Ȼ�޷��ɹ�����
```py
 self.retranslateUi(ChattingBot)
        # ��ť�¼�����
        # self.Enter.clicked['bool'].connect(lambda: self.buttonClicked(ChattingBot))
        self.Enter.clicked['bool'].connect(self.chatting)
        self.Enter.clicked['bool'].connect(self.InputText.clear)
        self.close.clicked['bool'].connect(ChattingBot.close)  # ֱ�ӹرյ�ǰ����
        # ���º�ֻ֤��һ����ť����
        self.basic.triggered.connect(lambda: self.mode_select(ChattingBot))
        self.DeepLearning.triggered.connect(lambda: self.mode_select(ChattingBot))
        self.api.triggered.connect(lambda: self.mode_select(ChattingBot))
        # QtCore.QMetaObject.connectSlotsByName(ChattingBot)
```

### �����޸�

����GUI����Ϊ���նԻ��Ľ��� ������Ҫ����һЩ�޸�

- ȷ��ֻ��һ��ģʽ����
  ```py
  def mode_select(self, ChattingBot):
        """ѡ��ģʽʱȷ��ֻ��һ��ģʽ��ʹ��"""
        sender = ChattingBot.sender()
        if sender == self.basic:
            if not self.basic.isChecked():  # ��Ψһһ�����ŵİ�����ȥ
                self.basic.setChecked(True)
            else:
                self.DeepLearning.setChecked(False)
                self.api.setChecked(False)
        if sender == self.DeepLearning:
            if not self.DeepLearning.isChecked():  # ��Ψһһ�����ŵİ�����ȥ
                self.DeepLearning.setChecked(True)
            else:
                self.basic.setChecked(False)
                self.api.setChecked(False)
        if sender == self.api:
            if not self.api.isChecked():  # ��Ψһһ�����ŵİ�����ȥ
                self.api.setChecked(True)
            else:
                self.basic.setChecked(False)
                self.DeepLearning.setChecked(False)
  ```

- ״̬��ȡ
  ```py
  def getState(self) -> int:
        if self.api.isChecked():
            return 3
        if self.DeepLearning.isChecked():
            return 2
        if self.basic.isChecked():
            return 1
  ```

- �Ի�
  ```py
  def chatting(self):
        """�����Ƿ���input���ı�������ģ��"""
        content = self.InputText.toPlainText()
        # TODO�� ��������ģ�����������ͨ��
        state = self.getState()
        result = ''
        if state == 1:
            self.OutputText.setText('���ڱ������� ��ģ�鲻����')
            return
        if state == 2:
            if is_en(content[0]):
                result = DLEChat(content)
            else:
                result = DLCChat(content)
        if state == 3:
            result = apiChat(content)

        ans = 'You:' + content + '\nBot:' + result  # ansΪ���ջظ�
        self.OutputText.setText(ans)

  def apiChat(x: str) -> str:
      return bot.chat(x, 'me')


  def DLEChat(x: str) -> str:
      """Ӣ�İ����ѧϰ"""
      return Etalk.talk(x)


  def DLCChat(x: str) -> str:
      """���İ����ѧϰ"""
      return Ctalk.talk(x)


  def is_en(w) -> bool:
      if 'a' <= w <= 'z' or 'A' <= w <= 'Z':
          return True
      else:
          return False
  ```

Ч��չʾ:
![������](./image/%E8%81%8A%E5%A4%A9%E7%BB%93%E6%9E%9C1.png)

## html����

### ǰ�˲���


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

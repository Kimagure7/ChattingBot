# ChattingBot ʵ�鱨��

- [ChattingBot ʵ�鱨��](#chattingbot-ʵ�鱨��)
  - [��Ա](#��Ա)
  - [�����ַ���ƥ���basic����](#�����ַ���ƥ���basic����)
  - [����Pytorch�����ѧϰ����](#����pytorch�����ѧϰ����)
  - [���ڵ���api��api����](#���ڵ���api��api����)
  - [GUI����](#gui����)
    - [��ťλ�ö���](#��ťλ�ö���)
    - [�˵�������](#�˵�������)
    - [��ť���֡���ʾ������ݼ�����](#��ť������ʾ����ݼ�����)
    - [��ť�¼�����](#��ť�¼�����)
    - [�����޸�](#�����޸�)
  - [html����](#html����)


## ��Ա

- ����
- ����
- ����
- ������

## �����ַ���ƥ���basic����

## ����Pytorch�����ѧϰ����

## ���ڵ���api��api����

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
import sys

from PyQt6 import QtCore, QtGui, QtWidgets
from PyQt6.QtWidgets import QApplication, QMainWindow
# from runTalking import *
import bot

class Ui_ChattingBot(object):

    def setupUi(self, ChattingBot):
        """初始化窗口"""
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
            self.OutputText.setText('还没弄好')
            return
        if state == 3:
            result = apiChat(content)

        ans = 'You:'+content+'\nBot:'+result # ans为最终回复
        self.OutputText.setText(ans)

    def getState(self) -> int:
        if self.api.isChecked():
            return 3
        if self.DeepLearning.isChecked():
            return 2
        if self.basic.isChecked():
            return 1

def apiChat(x:str) -> str:
    return bot.chat(x,'me')

def dlChat(x:str) -> str:
    pass

if __name__ == '__main__':
    app = QApplication(sys.argv)
    myw = QMainWindow()
    Ui_ChattingBot().setupUi(myw)
    myw.show()
    sys.exit(app.exec())

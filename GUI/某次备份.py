import sys

from PyQt6 import QtCore, QtGui, QtWidgets
from PyQt6.QtWidgets import QApplication, QMainWindow


class Ui_ChattingBot(object):

    def setupUi(self, ChattingBot):
        """初始化窗口"""
        # 主窗口
        ChattingBot.setObjectName("ChattingBot")
        ChattingBot.resize(800, 600)
        centralwidget = QtWidgets.QWidget(ChattingBot)
        centralwidget.setObjectName("centralwidget")

        Enter = QtWidgets.QPushButton(centralwidget)
        Enter.setGeometry(QtCore.QRect(457, 440, 81, 24))
        Enter.setObjectName("Enter")

        OutputText = QtWidgets.QTextBrowser(centralwidget)
        OutputText.setGeometry(QtCore.QRect(71, 41, 471, 291))
        OutputText.setObjectName("OutputText")

        InputText = QtWidgets.QTextEdit(centralwidget)
        InputText.setGeometry(QtCore.QRect(70, 350, 471, 81))
        InputText.setObjectName("InputText")

        line = QtWidgets.QFrame(centralwidget)
        line.setGeometry(QtCore.QRect(70, 330, 471, 21))
        line.setFrameShape(QtWidgets.QFrame.Shape.HLine)
        line.setFrameShadow(QtWidgets.QFrame.Shadow.Sunken)
        line.setObjectName("line")

        close = QtWidgets.QPushButton(centralwidget)
        close.setGeometry(QtCore.QRect(370, 440, 75, 24))
        close.setObjectName("close")

        ChattingBot.setCentralWidget(centralwidget)

        # 模式选择组件

        menubar = QtWidgets.QMenuBar(ChattingBot)
        menubar.setGeometry(QtCore.QRect(0, 0, 800, 22))
        menubar.setObjectName("menubar")
        options = QtWidgets.QMenu(menubar)
        options.setObjectName("settings")
        mode = QtWidgets.QMenu(options)
        mode.setObjectName("mode")
        ChattingBot.setMenuBar(menubar)
        statusbar = QtWidgets.QStatusBar(ChattingBot)
        statusbar.setObjectName("statusbar")
        ChattingBot.setStatusBar(statusbar)

        # 三大模式
        # 默认是dl模式
        basic = QtGui.QAction(ChattingBot)
        basic.setCheckable(True)
        basic.setChecked(False)
        basic.setObjectName("basic")
        basic.setStatusTip('基于字符串匹配实现')
        DeepLearning = QtGui.QAction(ChattingBot)
        DeepLearning.setCheckable(True)
        DeepLearning.setChecked(True)
        DeepLearning.setObjectName("DeepLearning")
        DeepLearning.setStatusTip('基于Pytorch实现')
        api = QtGui.QAction(ChattingBot)
        api.setCheckable(True)
        api.setChecked(False)
        api.setObjectName("API")
        mode.addAction(basic)
        mode.addAction(DeepLearning)
        mode.addAction(api)
        options.addAction(mode.menuAction())
        menubar.addAction(options.menuAction())

        # 按钮事件定义
        Enter.clicked['bool'].connect(InputText.clear)
        close.clicked['bool'].connect(ChattingBot.close)  # 直接关闭当前窗口
        # 按下后保证只有一个按钮亮起
        basic.triggered.connect(InputText.clear)
        DeepLearning.triggered.connect(self.mode_select)
        api.triggered.connect(self.mode_select)

        QtCore.QMetaObject.connectSlotsByName(ChattingBot)

        # 处理名字
        _translate = QtCore.QCoreApplication.translate
        ChattingBot.setWindowTitle(_translate("ChattingBot", "MainWindow"))
        Enter.setText(_translate("ChattingBot", "发送"))
        close.setText(_translate("ChattingBot", "关闭"))
        options.setTitle(_translate("ChattingBot", "settings"))
        mode.setTitle(_translate("ChattingBot", "mode"))
        basic.setText(_translate("ChattingBot", "basic"))
        basic.setToolTip(_translate("ChattingBot", "基于字符串匹配实现"))
        DeepLearning.setText(_translate("ChattingBot", "DeepLearning"))
        DeepLearning.setToolTip(_translate("ChattingBot", "基于Pytorch实现"))
        api.setText(_translate("ChattingBot", "api"))
        api.setToolTip(_translate("ChattingBot", "基于API调用实现"))

    def mode_select(self, ChattingBot):
        """选择模式时确保只有一个模式在使用"""
        ChattingBot.statusBar().showMessage('sda')


if __name__ == '__main__':
    app = QApplication(sys.argv)
    myw = QMainWindow()
    Ui_ChattingBot().setupUi(myw)
    myw.show()
    sys.exit(app.exec())

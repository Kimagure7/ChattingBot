import sys
from PyQt6.QtWidgets import QApplication, QMainWindow
from untitled import Ui_ChattingBot

if __name__ == '__main__':
    app = QApplication(sys.argv)
    myw = QMainWindow()
    myWin = Ui_ChattingBot().setupUi(myw)
    myw.show()
    sys.exit(app.exec())

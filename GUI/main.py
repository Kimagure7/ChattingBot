import sys
from PyQt6.QtWidgets import QApplication, QMainWindow
from untitled import Ui_MainWindow

if __name__ == '__main__':
    app = QApplication(sys.argv)
    myw = QMainWindow()
    myWin = Ui_MainWindow().setupUi(myw)
    myw.show()
    sys.exit(app.exec())

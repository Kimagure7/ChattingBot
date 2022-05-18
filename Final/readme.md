该文件夹作用是 

将各模块文件整合到一起以防止import灾难的发生

Bot文件就是api里面的

DeepLearning 有中英文版本 E=English C=Chinese final.py为客户端主模块,backend为网页端主模块

index.html resource文件夹 backend.py都是html文件夹下稍作更改(用于整合)得到的

网页端使用方法:
    py环境需要flask模块
    python3 backend.py
    浏览器打开http://127.0.0.1:8765
    选择模式send即可
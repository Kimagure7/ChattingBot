'''
Author: MomoTori
Date: 2022-05-18 20:58:05
LastEditors: MomoTori
LastEditTime: 2022-06-02 15:55:45
FilePath: \ChattingBotc:\Users\杨涛\Desktop\新建文件夹\talking.py
Description: 
Copyright (c) 2022 by MomoTori, All Rights Reserved. 
'''

line1=""
line2=""
lineList=[]

def foo(fileName):
    with open(fileName,"r",encoding="utf=8") as input:
        while True:
            line1=input.readline()
            if line1=="":
                break
            line1=line1.strip()
            if line1=="":
                continue
            if line1[0]=="「":
                line2=input.readline()
                line2=input.readline()
                if line2=="":
                    break
                line2=line2.strip()
                if line2=="":
                    continue
                if line2[0]=="「":
                    line1=line1[1:-1]
                    line2=line2[1:-1]
                    lineList.append(line1.strip()+"\t"+line2.strip())

    with open("de"+fileName,"w",encoding="utf=8") as out:
        for line in lineList:
            out.write(line+"\n")
        


fileName="wuzhi-_18_"

for i in range(18,25):
    fileName="wuzhi-_"+str(i)+"_.txt"
    foo(fileName)
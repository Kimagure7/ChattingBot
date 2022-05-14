import os

main = "python.exe --version"

f = os.popen(main)

data = f.readlines()[0]
data = data[0:len(data) - 1]
f.close()

print(data)

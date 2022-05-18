from flask import Flask,request,send_from_directory

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
        reply=default(msg)
    elif mode=='NeuralNetwork':
        reply=nn(msg)
    else:
        reply=api(msg)
    print(f'reply:\n{reply}')
    return reply

# handle requested resources e.g. images, js files
@app.route('/resource/<path:path>')
def send_report(path):
    return send_from_directory('resource', path)

# handle default
def default(msg):
    return 'default mode message'

# handle neural network
def nn(msg):
    return 'nn mode message'

#handle api
def api(msg):
    return 'api mode message'



if __name__=='__main__':
    app.run(host='127.0.0.1',port=8765)
    print('running on 127.0.0.1:8765')
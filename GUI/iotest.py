# coding=gb2312
import asyncio

@asyncio.coroutine
def hello():
    print("Hello world!")
    # �첽����asyncio.sleep(1):
    r = yield from asyncio.sleep(1)
    print("Hello again!")

# ��ȡEventLoop:
loop = asyncio.get_event_loop()
# ִ��coroutine
loop.run_until_complete(hello())
loop.close()
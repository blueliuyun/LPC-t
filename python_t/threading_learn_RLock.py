# -*- coding: utf-8 -*-
"""
Created on Wed Jul 12 12:19:51 2017

@author: Tian

RLock（可重入锁）是一个可以被同一个线程请求多次的同步指令。
RLock使用了“拥有的线程”和“递归等级”的概念，处于锁定状态
时，RLock被某个线程拥有。拥有RLock的线程可以再次调用acquire()，
释放锁时需要调用release()相同次数。
可以认为RLock包含一个锁定池和一个初始值为0的计数器，
每次成功调用 acquire()/release()，计数器将+1/-1，为0时锁处于
未锁定状态。

构造方法：
RLock()

实例方法：
acquire([timeout])/release(): 跟Lock差不多。

"""

import threading
import time

rlock = threading.RLock()

def func():
    # 第一次请求锁定
    print( '%s acquire lock...' % threading.currentThread().getName())
    if rlock.acquire():
        print( '%s get the lock.' % threading.currentThread().getName())
        time.sleep(2)
        # 第二次请求锁定
        print( '%s acquire lock again...' % threading.currentThread().getName())
        if rlock.acquire():
            print( '%s get the lock.' % threading.currentThread().getName())
            time.sleep(2)
        # 第一次释放锁
        print( '%s release lock...' % threading.currentThread().getName())
        rlock.release()
        time.sleep(2)
        # 第二次释放锁
        print( '%s release lock...' % threading.currentThread().getName())
        rlock.release()
        
t1 = threading.Thread(target=func, name='t1')
t2 = threading.Thread(target=func, name='t2')
t3 = threading.Thread(target=func, name='t3')
t1.start()
t2.start()
t3.start()
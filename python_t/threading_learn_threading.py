# -*- coding: utf-8 -*-
"""
Created on Wed Jul 12 09:52:49 2017

@author: Tian

threading 模块提供的常用方法：
threading.currentThread(): 返回当前的线程变量。
threading.enumerate(): 返回一个包含正在运行的线程的list。正在运行指线程启动后、结束前，不包括启动前和终止后的线
程。
threading.activeCount(): 返回正在运行的线程数量，与len(threading.enumerate())有相同的结果。

threading模块提供的类：
Thread-线程类, Lock, Rlock, Condition, [Bounded]Semaphore, Event, Timer, local.

"""

import threading
import time

#
def context(tJoin):
    print('In threadContext')
    tJoin.start()
    #
    #tList = threading.enumerate()
    #print(tList)
    tJoin.join()
    #
    print('Out threadContext')
    
def join():
    print('In threadJoin')
    time.sleep(1)
    print('Out threadJoin')
    
tJoin = threading.Thread(target=join, name='j')
tContext = threading.Thread(target=context, name='c', args=(tJoin,))

tContext.start()
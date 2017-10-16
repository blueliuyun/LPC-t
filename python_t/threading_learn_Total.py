# -*- coding: utf-8 -*-
"""
Created on Wed Jul 12 14:16:31 2017

@author: Tian
"""

import threading
alist = None
condition = threading.Condition()

# func
def doSet():
    if condition.acquire():
        while alist is None:
            condition.wait()
        for i in range(len(alist))[::-1]:
            alist[i] = 2
        print('release:doSet')
        condition.release()

def doPrint():
    if condition.acquire():
        while alist is None:
            condition.wait()
        for i in alist:
            print( i)
        print('release:doPrint')
        condition.release()

def doCreate():
    global alist
    if condition.acquire():
        if alist is None:
            alist = [i for i in range(0, 10)]
            condition.notifyAll()
        print('release:doCreate')
        condition.release()

# main
tset = threading.Thread(target=doSet,name='tset')
tprint = threading.Thread(target=doPrint,name='tprint')
tcreate = threading.Thread(target=doCreate,name='tcreate')
tset.start()
tprint.start()
tcreate.start()
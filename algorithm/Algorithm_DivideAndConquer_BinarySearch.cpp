///////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////
// 头文件
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
//typedef unsigned int uint32;


///////////////////////////////////////////////////////////////
// API 
int binarySerach(vector<int> array, int nRes);
int binarySerach(vector<int> array, int nLow, int nHigh, int nRes);

///////////////////////////////////////////////////////////////
// 
int main(void)
{
    int buf[] = {1,3,5,19,21,89};	
    vector<int> vec;
    
    // 二分查找
    for (int i=0; i<(sizeof(buf)/sizeof(int)); i++)
    {
          vec.push_back(buf[i]);
          //cout << vec[i] << " ";
    }
	binarySerach(vec, 4);
	// 
	system("pause");
	return 0;
}

///////////////////////////////////////////////////////////////
// @2017-10-11 二分查找
// (1) 返回值：返回待查找 nRes 在 vector 中的下标。其中 vector下标
//    从 0 开始。 
int binarySerach(vector<int> array, int nRes) 
{
    // (1) @2017-10-11 默认，二分查找的目标是有序数组（升序）。
    //    因此，如果传递的数组是无序的，则需要先排序。 
    // (2)
    return binarySerach(array, 0, array.size()-1, nRes);
}

int binarySerach(vector<int> array, int nLow, int nHigh, int nRes) 
{
    if (nLow > nHigh)
    {
        cout << "No Item." << endl;   
        return -1;    
    }
    int nMid = (nLow + nHigh)/2;      // 数组下标中间值 
    if (nRes == array[nMid])          // nRes与数组中间值比较 
        return nMid;
    else if (nRes < array[nMid])
        return binarySerach(array, nLow, nMid-1, nRes);       //数组内容不变，移动范围下标 
    else
        return binarySerach(array, nMid+1, nHigh, nRes);
}

///////////////////////////////////////////////////////////////
// @2017-10-11 二分查找

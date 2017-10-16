///////////////////////////////////////////////////////////////
//
// @2017-10-11 快速排序  
//
///////////////////////////////////////////////////////////////
// 头文件
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;
//typedef unsigned int uint32;


///////////////////////////////////////////////////////////////
// API 
int Partition(vector<int>::iterator pVec, int nLow, int nHigh);
void QuickSort(vector<int>::iterator pVec, int nLow, int nHigh);
void Swap(vector<int>::iterator pVec, int p, int q);

///////////////////////////////////////////////////////////////
// 
int main(void)
{
    int buf[] = {8,121,13,5,19,21,89};	
    vector<int> vec;
    
    // 赋初值 
    for (int i=0; i<(sizeof(buf)/sizeof(int)); i++)
    {
          vec.push_back(buf[i]);
          //cout << vec[i] << " ";
    }
    
    // 排序 
	QuickSort(vec.begin(), 0, (vec.size()-1));
	
    // 打印 
    for (int i=0; i<(sizeof(buf)/sizeof(int)); i++)
    {
          //vec.push_back(buf[i]);
          cout << vec[i] << " ";
    }
	system("pause");
	return 0;
}

///////////////////////////////////////////////////////////////
// @2017-10-11 快速排序 
// (1) 形参：nLow < nHigh, 需排序的数组下标 
//
void QuickSort(vector<int>::iterator pVec, int nLow, int nHigh)
{
    if (nLow >= nHigh)    // check 输入数组下标 
    {
        //cout << "Left need < Right." << endl;   
        return ;    
    }

    if (nLow < nHigh)
    {
        int nIndex = Partition(pVec, nLow, nHigh); 
        QuickSort(pVec, nLow, nIndex-1);
        QuickSort(pVec, nIndex+1, nHigh);    
    }
}

// 返回中间分隔的数组下标 
int Partition(vector<int>::iterator pVec, int nLow, int nHigh)
{    
    int i=nLow-1;
    for ( int j=nLow; j<nHigh; j++)
    {
        if (*(pVec+j) < *(pVec+nHigh))
        {
             i++;
             if (i != j) std::swap(*(pVec+i), *(pVec+j));
        }
    }
    std::swap(*(pVec+i+1), *(pVec+nHigh));
    return (i+1);
}

// Data swop function   
// 使用方法： Swap(pVec, i, j) 
// @2017-10-11 由于 std:: 有标准 swap, 所以不使用自定义 Swap      
void Swap(vector<int>::iterator pVec, int p, int q)
{
    int temp = *(pVec+p);
    *(pVec+p)=*(pVec+q);
    *(pVec+q)=temp;
    cout << *(pVec+p) << "      " << *(pVec+q) << endl;
}

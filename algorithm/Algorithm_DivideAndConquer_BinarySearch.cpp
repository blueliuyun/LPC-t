///////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////
// ͷ�ļ�
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
    
    // ���ֲ���
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
// @2017-10-11 ���ֲ���
// (1) ����ֵ�����ش����� nRes �� vector �е��±ꡣ���� vector�±�
//    �� 0 ��ʼ�� 
int binarySerach(vector<int> array, int nRes) 
{
    // (1) @2017-10-11 Ĭ�ϣ����ֲ��ҵ�Ŀ�����������飨���򣩡�
    //    ��ˣ�������ݵ�����������ģ�����Ҫ������ 
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
    int nMid = (nLow + nHigh)/2;      // �����±��м�ֵ 
    if (nRes == array[nMid])          // nRes�������м�ֵ�Ƚ� 
        return nMid;
    else if (nRes < array[nMid])
        return binarySerach(array, nLow, nMid-1, nRes);       //�������ݲ��䣬�ƶ���Χ�±� 
    else
        return binarySerach(array, nMid+1, nHigh, nRes);
}

///////////////////////////////////////////////////////////////
// @2017-10-11 ���ֲ���

///////////////////////////////////////////////////////////////
//
// @2017-10-11 ��������  
//
///////////////////////////////////////////////////////////////
// ͷ�ļ�
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
    
    // ����ֵ 
    for (int i=0; i<(sizeof(buf)/sizeof(int)); i++)
    {
          vec.push_back(buf[i]);
          //cout << vec[i] << " ";
    }
    
    // ���� 
	QuickSort(vec.begin(), 0, (vec.size()-1));
	
    // ��ӡ 
    for (int i=0; i<(sizeof(buf)/sizeof(int)); i++)
    {
          //vec.push_back(buf[i]);
          cout << vec[i] << " ";
    }
	system("pause");
	return 0;
}

///////////////////////////////////////////////////////////////
// @2017-10-11 �������� 
// (1) �βΣ�nLow < nHigh, ������������±� 
//
void QuickSort(vector<int>::iterator pVec, int nLow, int nHigh)
{
    if (nLow >= nHigh)    // check ���������±� 
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

// �����м�ָ��������±� 
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
// ʹ�÷����� Swap(pVec, i, j) 
// @2017-10-11 ���� std:: �б�׼ swap, ���Բ�ʹ���Զ��� Swap      
void Swap(vector<int>::iterator pVec, int p, int q)
{
    int temp = *(pVec+p);
    *(pVec+p)=*(pVec+q);
    *(pVec+q)=temp;
    cout << *(pVec+p) << "      " << *(pVec+q) << endl;
}

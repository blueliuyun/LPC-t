///////////////////////////////////////////////////////////////
//
// @2017-10-13 DP : LCS ����������� 
// ʱ�临�Ӷ� O(n*m)
// �ռ临�Ӷ� O(n*m)
// 
///////////////////////////////////////////////////////////////
// ͷ�ļ�
//#include <stdarg.h>
//#include <string.h>
//#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;
//typedef unsigned int uint32;

//@2017-10-13 TY �迼��ʹ�ñ䳤������ , ����ʹ�� vector ʵ�ֱ䳤��ά���� 
#define ArraySize 16
int dp[ArraySize][ArraySize]={0};

///////////////////////////////////////////////////////////////
// DP LCS API
void DpLCS(vector<char>::iterator pVecX, vector<char>::iterator pVecY, int x, int y);

///////////////////////////////////////////////////////////////
// 
int main(void)
{
    char cBufX[] = {'A', 'B', 'C', 'B', 'D', 'A', 'B'};
    char cBufY[] = {'B', 'D', 'C', 'A', 'B', 'A'};
    
    vector<char> vecX, vecY;
    
    // ����ֵ
    for (int i=0; i<(sizeof(cBufX)/sizeof(char)); i++)
    {
          vecX.push_back(cBufX[i]);
          //cout << vecX[i] << " ";
    }
    cout << endl;
    for (int i=0; i<(sizeof(cBufY)/sizeof(char)); i++)
    {
          vecY.push_back(cBufY[i]);
          //cout << vecY[i] << " ";
    } 
    
    // DP : LCS 
    // ��ά����洢���� ״̬���� ��ֵ 
    for (int i=0; i<vecX.size(); i++)
    {
        for (int j=0; j<vecY.size(); j++)
        {
            if (vecX.at(i) == vecY.at(j))
            {
                dp[i+1][j+1] = dp[i][j]+1;
            }
            else
            {
                dp[i+1][j+1] = std::max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }
    /*
    // ��ӡ ��� content 
    for (int i=0; i<ArraySize; i++)
    {
        for (int j=0; j<ArraySize; j++)
        {
             cout << dp[i][j] << ' ';      
        }
        cout << endl;
    } 
    */   
    // Graph 
    DpLCS(vecX.begin(), vecY.begin(), vecX.size(), vecY.size());
    
	system("pause");
	return 0;
}

///////////////////////////////////////////////////////////////
// @2017-10-13 DP LCS
// DP : LCS
// (1) �����н�β��ǰ�ݹ�. 
// (2) �����ı߽�������  return ;
void DpLCS(vector<char>::iterator pVecX, vector<char>::iterator pVecY, int x, int y) 
{
    if (x == 0 || y == 0)
        return ;
    if (*(pVecX+x-1) == *(pVecY+y-1))
    {
        DpLCS(pVecX, pVecY, x-1, y-1);
        cout << *(pVecX+x-1) << ' ';
    }
    else if (dp[x-1][y] == dp[x][y])
    {
         DpLCS(pVecX, pVecY, x-1, y);
    }
    else
    {
        DpLCS(pVecX, pVecY, x, y-1);
    }
}

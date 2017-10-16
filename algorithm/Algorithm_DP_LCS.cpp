///////////////////////////////////////////////////////////////
//
// @2017-10-13 DP : LCS 最长公共子序列 
// 时间复杂度 O(n*m)
// 空间复杂度 O(n*m)
// 
///////////////////////////////////////////////////////////////
// 头文件
//#include <stdarg.h>
//#include <string.h>
//#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;
//typedef unsigned int uint32;

//@2017-10-13 TY 需考虑使用变长度数组 , 考虑使用 vector 实现变长二维数组 
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
    
    // 赋初值
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
    // 二维数组存储的是 状态方程 的值 
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
    // 打印 表格 content 
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
// (1) 从数列结尾向前递归. 
// (2) 结束的边界条件是  return ;
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

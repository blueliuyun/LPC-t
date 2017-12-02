/************************************************************************
 * @2017-12-01 C++98                                          
 *  (1)函数模板 
 *		template<typename T>
 *		<返回类型> <函数名>(参数表) 
 * 		{
 *			// 函数体 
 *		}
 *		其中，关键字 typename 也可以使用关键字 class  
 *		函数模板允许使用多个类型参数，即 template<class T1, class T2, ..., class Tn> 
************************************************************************/

/* Header file */
#include <stdio.h>
#include <iostream>
#include <vector>

/* namespace */
using namespace std;

/* 函数模板 1, 形参类型必须相同*/
template<typename T>
T TMin(T a, T b)
{
	return (a<b)?a:b;
}

/* 函数模板 2, 形参类型可以不同*/
template<class T, class U>
U TSum(T a, U b)
{
	return (a+b);
}

/* Class */
template<class T>
class Ope{
      public:
      static T Add(T a, T b){
             return (a+b);
      }
      static T Mul(T a, T b){
             return (a*b);
      }
};

int main()
{
	int x=6, y=9;
	float z=3.14; 
	printf("TMin = %d\r\n", TMin(x, y));
	printf("TMax = %f\r\n", TSum(x, z));
	// pause
	system("pause");
	return 0;
}                  

//

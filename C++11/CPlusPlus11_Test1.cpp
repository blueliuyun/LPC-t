/************************************************************************/
/* @2017-12-01 C++11 右值引用                                           */
/*  (1)模板 */
/************************************************************************/

/* Header file */
#include <stdio.h>
#include <iostream>
#include <vector>

/* namespace */
using namespace std;

/* 函数声明 */

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
	std::move();
	// pause
	system("pause");
	return 0;
}                  

//

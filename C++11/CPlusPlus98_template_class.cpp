/************************************************************************
 * @2017-12-04 C++98                                          
 *  (1)前言：C++标准库是基于模版技术构建的， 
 *	   在C++标准库中模版共分为2中，一种是类模板，还有一种是函数模版。 
 *  (2)类模板 
 *		template<class T>
 *		class XYZ{
 *			protected:
 *				T *a;     // 成员1
 *				int size; // 成员2
 *			public:
 *				T &operator[](int);
 *				void mput(T b); // mput()函数的参数b的类型是T
 *		};
 *		然后就可以使用 A<int> y; 定义类的对象。 <== 模板实例化
 *      成员函数定义 ==>	templeate<class T> 
 *							void XYZ<T>::mput(T b) {}
 *		!!! 类的成员名不能与模板参数type同名。
 *      !!! 模板参数type可以在不同的模板间重复使用。 
 *      !!! 从通用的类模板定义中生成类的过程称为模板实例化。 类模板是对一批仅仅成员数据类型不同的类的抽象。
 *			模板实例化 ==>  类名 <数据类型 1(或数据)，数据类型 2(或数据)…> 对象名
 *	(3)eg.
 *		 template<class type, int width> 	// 其中，type 是类型参数； width 是非类型参数 
 *
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

/* Class 模板 */
template<class T>
class OPE{
      public:
		  T Add(T a, T b);
		  T Mul(T a, T b){
             return (a*b);
		  }
};
/* Class 模板 成员函数的实现 */
template<class T>
T OPE<T>::Add(T a, T b){
	return (a + b);
};
/* 类 */

int main()
{
	/* Param Init */
	int x = 19, y = 11;
	OPE<int> cTest;
	
	printf("Add() = %d\r\n", cTest.Add(x, y));
	/* pause */
	system("pause");
	return 0;
}                  

//

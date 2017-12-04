/************************************************************************
 * @2017-12-04 C++98                                          
 *  (1)ǰ�ԣ�C++��׼���ǻ���ģ�漼�������ģ� 
 *	   ��C++��׼����ģ�湲��Ϊ2�У�һ������ģ�壬����һ���Ǻ���ģ�档 
 *  (2)��ģ�� 
 *		template<class T>
 *		class XYZ{
 *			protected:
 *				T *a;     // ��Ա1
 *				int size; // ��Ա2
 *			public:
 *				T &operator[](int);
 *				void mput(T b); // mput()�����Ĳ���b��������T
 *		};
 *		Ȼ��Ϳ���ʹ�� A<int> y; ������Ķ��� <== ģ��ʵ����
 *      ��Ա�������� ==>	templeate<class T> 
 *							void XYZ<T>::mput(T b) {}
 *		!!! ��ĳ�Ա��������ģ�����typeͬ����
 *      !!! ģ�����type�����ڲ�ͬ��ģ����ظ�ʹ�á� 
 *      !!! ��ͨ�õ���ģ�嶨����������Ĺ��̳�Ϊģ��ʵ������ ��ģ���Ƕ�һ��������Ա�������Ͳ�ͬ����ĳ���
 *			ģ��ʵ���� ==>  ���� <�������� 1(������)���������� 2(������)��> ������
 *	(3)eg.
 *		 template<class type, int width> 	// ���У�type �����Ͳ����� width �Ƿ����Ͳ��� 
 *
************************************************************************/

/* Header file */
#include <stdio.h>
#include <iostream>
#include <vector>

/* namespace */
using namespace std;

/* ����ģ�� 1, �β����ͱ�����ͬ*/
template<typename T>
T TMin(T a, T b)
{
	return (a<b)?a:b;
}

/* ����ģ�� 2, �β����Ϳ��Բ�ͬ*/
template<class T, class U>
U TSum(T a, U b)
{
	return (a+b);
}

/* Class ģ�� */
template<class T>
class OPE{
      public:
		  T Add(T a, T b);
		  T Mul(T a, T b){
             return (a*b);
		  }
};
/* Class ģ�� ��Ա������ʵ�� */
template<class T>
T OPE<T>::Add(T a, T b){
	return (a + b);
};
/* �� */

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

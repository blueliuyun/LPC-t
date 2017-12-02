/************************************************************************
 * @2017-12-01 C++98                                          
 *  (1)����ģ�� 
 *		template<typename T>
 *		<��������> <������>(������) 
 * 		{
 *			// ������ 
 *		}
 *		���У��ؼ��� typename Ҳ����ʹ�ùؼ��� class  
 *		����ģ������ʹ�ö�����Ͳ������� template<class T1, class T2, ..., class Tn> 
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

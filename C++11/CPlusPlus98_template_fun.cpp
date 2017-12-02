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

/* ����ģ�� */
template<typename T>
T TMin(T a, T b)
{
	return (a<b)?a:b;
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
	int x=6, y=9, z;
	z = TMin(x, y);
	printf("%d", z);
	// pause
	system("pause");
	return 0;
}                  

//

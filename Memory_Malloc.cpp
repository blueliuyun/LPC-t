////////////////////////////////////////////////////////////////
// 
// @2017-10-23
// ��1������VS2005/VS2008�������Դ����ڴ��⹤��/����.
//		#include <crtdbg.h>
// @2017-10-24
// ��1����֤ malloc() ���� ���� heap �ϵ��ڴ�.
//
////////////////////////////////////////////////////////////////

// Memory Leak
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

// ͷ�ļ�
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

// �����ռ�
using namespace std;

// ��
#define PRINTF_BUFFER_COUNT 512


// ��������
char * isprintf(const char * format, ...);
char * ivsprintf(const char * format, va_list args);
void print(vector<int> v);

// Class
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

// ���� new ������, �������ּ�� �ڴ�й©
#define new new(_CLIENT_BLOCK, __FILE__, __LINE__)	

//
int main()
{
	// Test : Memory Leak 
	int* leak = new int[10];

    int x=1, y=2, z=3;
    int u, v;
    u = Ope<int>::Add(x, y);
    v = Ope<int>::Mul(y, z);
    cout << "u=" << u << endl;
    cout << "v=" << v << endl;
    
	//delete [] leak;	// Test : Memory Leak 


	// Test : malloc()
	char *pChar = NULL;
	//pChar = (char *)malloc(sizeof(char)*10);		// s1.�����ڴ� malloc, ������ڴ�ռ�δ��ʼ��
	pChar = (char *)calloc(15, sizeof(char));
	
	if (pChar == NULL)		// s2. �������ڴ�ռ�󣬱������Ƿ����ɹ�!!!
	{
		cout << "Can't get memory!" << endl;
		return -1;
	}
	printf("pChar = %d\n", *pChar);	// s3. ��ӡ malloc()  �� calloc() �����ڴ�ռ����ݵ�����.
	memset(pChar, 'a', sizeof(char)*10);
	cout << *pChar << endl;
	//free(pChar);	// s-4 : �ͷ��ڴ�, malloc() , calloc() �������� free() �ͷ�
	pChar = NULL;	// s-5 : �ͷ��ڴ��ָ��ָ�� NULL


	// Test : Memory Leak  ����ж�Ӧ�� delete [],����Ҫ���ڴ˺���֮ǰ�� Line .
	_CrtDumpMemoryLeaks();
	// pause
	system("pause");
	return 0;
}                  

// 
char * ivsprintf(const char * format, va_list args)
{
	static char szBuffer[PRINTF_BUFFER_COUNT];
	vsprintf(szBuffer, format, args);
	return szBuffer;
}
//
char * isprintf(const char * format, ...)
{
	char * p;
	va_list args;
	va_start(args, format);
    p=ivsprintf(format, args);
	va_end(args);
	return p;
}

//
void print(vector<int> v)
{
     cout << "\n vector size is: " << v.size() << endl;
     vector<int>::iterator p = v.begin();
}


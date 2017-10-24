////////////////////////////////////////////////////////////////
// 
// @2017-10-23
// （1）对于VS2005/VS2008编译器自带的内存检测工具/函数.
//		#include <crtdbg.h>
// @2017-10-24
// （1）验证 malloc() 函数 申请 heap 上的内存.
//
////////////////////////////////////////////////////////////////

// Memory Leak
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

// 头文件
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

// 命名空间
using namespace std;

// 宏
#define PRINTF_BUFFER_COUNT 512


// 函数声明
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

// 重载 new 操作符, 代码入侵检测 内存泄漏
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
	//pChar = (char *)malloc(sizeof(char)*10);		// s1.申请内存 malloc, 申请的内存空间未初始化
	pChar = (char *)calloc(15, sizeof(char));
	
	if (pChar == NULL)		// s2. 申请了内存空间后，必须检查是否分配成功!!!
	{
		cout << "Can't get memory!" << endl;
		return -1;
	}
	printf("pChar = %d\n", *pChar);	// s3. 打印 malloc()  与 calloc() 申请内存空间内容的区别.
	memset(pChar, 'a', sizeof(char)*10);
	cout << *pChar << endl;
	//free(pChar);	// s-4 : 释放内存, malloc() , calloc() 都可以用 free() 释放
	pChar = NULL;	// s-5 : 释放内存后指针指向 NULL


	// Test : Memory Leak  如果有对应的 delete [],则需要放在此函数之前的 Line .
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


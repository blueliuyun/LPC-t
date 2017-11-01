/*
 * @2017-10-23
 *  ��1������VS2005/VS2008�������Դ����ڴ��⹤��/������
 *         #include <crtdbg.h>
 *  ��2�� Memory Leak Check 
 *
 */

//////////////////////////////////////////////////////////////////////////
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>


//////////////////////////////////////////////////////////////////////////
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

#ifndef WIN32
#include <netinet/in.h>
#ifdef _XOPEN_SOURCE_EXTENDED
#include <arpa/inet.h>
#endif
#include <sys/socket.h>
#endif

#include "event2/bufferevent.h"
#include "event2/buffer.h"
#include "event2/listener.h"
#include "event2/util.h"
#include "event2/event.h"

#include <WinSock2.h>

//////////////////////////////////////////////////////////////////////////
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

int main()
{
	#define new new(_CLIENT_BLOCK, __FILE__, __LINE__)	

	// Test 
	int* leak = new int[10];

    int x=1, y=2, z=3;
    int u, v;
    u = Ope<int>::Add(x, y);
    v = Ope<int>::Mul(y, z);
    cout << "u=" << u << endl;
    cout << "v=" << v << endl;
    
	//delete [] leak;

	_CrtDumpMemoryLeaks();	//@2017-10-23 ����ж�Ӧ�� delete [],����Ҫ���ڴ˺���֮ǰ�� Line .

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


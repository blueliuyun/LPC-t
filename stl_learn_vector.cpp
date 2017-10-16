////////////////////////////////////////////////////////////////
// 
// @2017-09-13
// （1）
//
////////////////////////////////////////////////////////////////
// 头文件
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

//
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

int main()
{
    int x=1, y=2, z=3;
    int u, v;
    u = Ope<int>::Add(x, y);
    v = Ope<int>::Mul(y, z);
    cout << "u=" << u << endl;
    cout << "v=" << v << endl;
    
    // pause
	system("pause");
	return 0;
}                  


/*
int main()
{ 	
	printf("%s\n", "start");

    // stl
    vector<int> vec;
    vec.push_back(35);
    vec.push_back(26);
    print(vec);
    
    vector<int>::iterator p;
    p = vec.begin();
    *p = 68;
    *(p+1) = 70;
    print(vec);
    vec.pop_back();
    print(vec);
    vec.push_back(101);
    vec.push_back(102);
    //
    int i = 0;
    while(i < vec.size())
    {
            cout << vec[i++] << " ";
    }
    cout << endl;
    //
    vec[0] = 1001;
    vec[1] = 1003;
    vec[2] = 1005;
    i = 0;
    while(i < vec.size())
    {
            cout << vec[i++] << " ";
    }
    cout << endl;
    
    // pause
	system("pause");
	return 0;
}
*/

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


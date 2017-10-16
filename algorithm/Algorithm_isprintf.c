////////////////////////////////////////////////////////////////
/// 
///
////////////////////////////////////////////////////////////////
/// 头文件
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/// 宏
#define PRINTF_BUFFER_COUNT 512
/// 变量
const short TenMultiple[]=
{   1,
    10,
	100,
	1000,
	10000,
	100000,
	1000000
};

/// 函数声明
char * isprintf(const char * format, ...);
char * ivsprintf(const char * format, va_list args);


/// 
void main()
{
	/// 函数 isprintf() 作用是返回一个类似 %d.%03d 的字符串, 此时 iPoint值为 3, 
	/// iPoint值为 3, 表示最终要格式化为 3 位小数点的字符串样式
	int value = 123456789;
	unsigned char iPoint = 3;
	char pValue[512];
	char * pTemp=isprintf("%%d.%%0%dd", iPoint);
	printf("%s\n", pTemp);

	sprintf(pValue, pTemp, value/TenMultiple[iPoint], value%TenMultiple[iPoint]);
	printf("%s\n", pValue);
	system("pause");
}

/// 
char * ivsprintf(const char * format, va_list args)
{
	static char szBuffer[PRINTF_BUFFER_COUNT];
	vsprintf(szBuffer, format, args);
	return szBuffer;
}
///
char * isprintf(const char * format, ...)
{
	char * p;
	va_list args;
	va_start(args, format);
    p=ivsprintf(format, args);
	va_end(args);

	return p;
}
///

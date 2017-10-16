////////////////////////////////////////////////////////////////
/// 
///
////////////////////////////////////////////////////////////////
/// ͷ�ļ�
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/// ��
#define PRINTF_BUFFER_COUNT 512
/// ����
const short TenMultiple[]=
{   1,
    10,
	100,
	1000,
	10000,
	100000,
	1000000
};

/// ��������
char * isprintf(const char * format, ...);
char * ivsprintf(const char * format, va_list args);


/// 
void main()
{
	/// ���� isprintf() �����Ƿ���һ������ %d.%03d ���ַ���, ��ʱ iPointֵΪ 3, 
	/// iPointֵΪ 3, ��ʾ����Ҫ��ʽ��Ϊ 3 λС������ַ�����ʽ
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

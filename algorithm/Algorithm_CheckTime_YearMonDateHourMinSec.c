///////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////
// ͷ�ļ�
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>



// One-based array of days in year at month start
static const int16 _MonthDays[13] =
	{0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

//�ж��Ƿ�������
/*
��������������������Ϊyear����

��1����year��400��������ʱΪ���꣬������ʾΪ��

year%400= =0

��2����year��4����������������100��������ʱΪ���꣬����Ϊ��

    year%4= =0 && year%100 != 0
*/

#define IsLeapYear(nYear) ((((nYear) & 3) == 0) && (((nYear) % 100) != 0 || ((nYear) % 400) == 0))

//����ĳ��ĳ���ж�����
#define GetDaysInMonth(nYear, nMon) (_MonthDays[nMon] - _MonthDays[(nMon)-1] + (((nMon) == 2 && IsLeapYear(nYear)) ? 1 : 0))


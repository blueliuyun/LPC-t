///////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////
// 头文件
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>



// One-based array of days in year at month start
static const int16 _MonthDays[13] =
	{0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

//判断是否是闰年
/*
闰年有两种情况，设年份为year，则：

（1）当year是400的整倍数时为闰年，条件表示为：

year%400= =0

（2）当year是4的整倍数，但不是100的整倍数时为闰年，条件为：

    year%4= =0 && year%100 != 0
*/

#define IsLeapYear(nYear) ((((nYear) & 3) == 0) && (((nYear) % 100) != 0 || ((nYear) % 400) == 0))

//计算某年某月有多少天
#define GetDaysInMonth(nYear, nMon) (_MonthDays[nMon] - _MonthDays[(nMon)-1] + (((nMon) == 2 && IsLeapYear(nYear)) ? 1 : 0))


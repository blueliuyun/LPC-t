////////////////////////////////////////////////////////////////
// 
// @2017-09-13
// ��1��ƽ������� 
// 
////////////////////////////////////////////////////////////////
/// ͷ�ļ�
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/// ��
#define PRINTF_BUFFER_COUNT 512


/// ����
typedef struct {
    int leftChild;
    int rightChild;
}TreeNode;

/// ��������
char * isprintf(const char * format, ...);
char * ivsprintf(const char * format, va_list args);
int maxDeep(TreeNode node);

/// 
int main()
{
	/// ���� 

	printf("%s\n", 1);

	system("pause");
	return 0;
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
int maxDeep(TreeNode node)
{
	if (1)//(node==NULL){
    {
		return 0;
	}
	int rightDeep=maxDeep(node.rightChild);
	int leftDeep=maxDeep(node.leftChild);
	
	return rightDeep>leftDeep?(rightDeep+1):(leftDeep+1);
}

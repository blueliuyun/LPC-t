///////////////////////////////////////////////////////////////
//
// @2017-10-17 R-B��
// ��1��ʱ�临�Ӷ� O(h)������ h �����ĸ߶ȡ� 
// ��2���ռ临�Ӷ� O()
// ��3������˵�� ��a.�����㣬�����������ɾ����㣬���������Сֵ�� 
//                 b.����ָ������ǰ���ͺ�̡� 
///////////////////////////////////////////////////////////////
// ͷ�ļ�
#include <iostream>
#include <vector>

// 
using namespace std;

// ����������������
typedef struct node {
	int item;
	struct node * pLeft;
	struct node * pRight;
} *pLink;
         
///////////////////////////////////////////////////////////////
// API
pLink Node(int item, pLink pLeft, pLink pRight);
pLink InsertNode(pLink p, int item);
pLink DeleteNode(pLink p, int item);

///////////////////////////////////////////////////////////////
// 
int main(void)
{
	pLink root = NULL;
    int uBufX[] = { 23, 11, 68, 39, 8, 46, 75, 71 };
        
    // ����ֵ
    for (int i=0; i<(sizeof(uBufX)/sizeof(int)); i++)
    {
          //vecX.push_back(uBufX[i]);
          InsertNode(root, uBufX[i]);
    }
	
	system("pause");
	return 0;
}

///////////////////////////////////////////////////////////////
// ��������Tree��� 2
///////////////////////////////////////////////////////////////
pLink Node(int item, pLink pLeft, pLink pRight)
{
	pLink p = (pLink)malloc(sizeof(*p));
	p->item = item;
	p->pLeft = pLeft;
	p->pRight = pRight;
	return p;
}

///////////////////////////////////////////////////////////////
// ���� 2
///////////////////////////////////////////////////////////////
pLink InsertNode(pLink p, int item)
{
	if (p==NULL)
		return Node(item, NULL, NULL);
	if (item < p->item)
		p->pLeft = InsertNode(p->pLeft, item);
	else
		p->pRight = InsertNode(p->pRight, item);
	return p;
}

///////////////////////////////////////////////////////////////
//
// ɾ�� - �迼�� 3 �������
// (1) û�к��ӽڵ㣬��ΪҶ�ӽ�㣬ɾ�����ӽ�㡣
// (2) ֻ�� 1 ������x��㡣�����ֱ�ӰѸ������Ӧ�ĺ���ָ��ָ��
//     �ú���x�Ķ����ӣ�ɾ�����ӽ�㡣
// (3) �� 2 �������������㣩������ѡ��������е����Ԫ�ػ��Ҷ�
//     ���е���СԪ�طŵ���ɾ������λ�á�ϰ���ϣ���ѡ���������
//     �����Ԫ�ء�
// (4) ������ɫ��ѡ��Ȳ�����
// (5) ���ɾ�����Ǻ�ɫ�ڵ㣬��RB�����ʱ��ֲ��䡣���ɾ�����Ǻ�ɫ
//     ��㣬��ôRB�������ʿ��ܻᷢ���ı䡣
// ������ɾ��α���룺
//
//
///////////////////////////////////////////////////////////////
pLink DeleteNode(pLink p, int item)
{
	
}
pLink DeleteNode(pLink p, int item)
{
	return p;
}
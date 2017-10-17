///////////////////////////////////////////////////////////////
//
// @2017-10-15  ��������� 
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
void Insert(pNode &root, KeyType key);
pNode SearchMinNode(pNode &root);
pLink Node(int item, pLink pLeft, pLink pRight);
pLink InsertNode(pLink p, int item);
pLink DeleteNode(pLink p, int item);

///////////////////////////////////////////////////////////////
// 
int main(void)
{
	pLink root = NULL;	// ���ڵ�
    int uBufX[] = {23, 11, 68, 39, 8, 46, 75, 71};
        
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
//  
// ������������в�����
// (1) �ȸ��� 
//
void Insert(pNode &root, KeyType key)
{
	// ��ʼ��������
	pNode p = (pNode)malloc(sizeof(stNode));
	p->key = key;
	p->left = p->right = p->parent = NULL;
	// ������as root 
	if(root == NULL)
	{
		root = p;
		return;
	}
	
	// ���뵽��ǰ���(root)������, ���е�ÿ�� key ֵ�Ĵ�С��ͬ 
	if((root)->left == NULL && (root)->key > key) 
	{
		p->parent = (root);
		(root)->left = p;
		return;
	}
	// ���뵽��ǰ���(*root)���Һ���
	if((root)->right == NULL && (root)->key < key) 
	{
		p->parent = (root);
		(root)->right = p;
		return;
	}

	if((root)->key > key) 
		Insert((root)->left, key);
	else if((root)->key < key)
		Insert((root)->right, key);
	else
		return; // �������ֵ == root��key���򷵻� 
}

///////////////////////////////////////////////////////////////
// 
// ������С�ؼ���,����ʱ����NULL
// (1) ����ֵ : pNode ���͵�ָ��
//
pNode SearchMinNode(pNode &root)
{
	if(root == NULL) 
	{
		return 0;
	}	
	if(root->left == NULL)	// ��������ʱ 	
	{
		return root;
	}	
	else  					// �������ǿ�ʱ 	
	{
		SearchMinNode(root->left);
	}
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
// ������ɾ��α���룺
//
//
///////////////////////////////////////////////////////////////
pLink DeleteNode(pLink p, int item)
{
	
}
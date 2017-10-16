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

typedef unsigned int KeyType;
typedef struct Node {
	KeyType key;			// �ؼ��� 
	struct Node * left;		// ����ָ�� 
	struct Node * right;	// �Һ���ָ�� 
	struct Node * parent; 	// ָ�򸸽ڵ�ָ�� 
}stNode, *pNode;

         
///////////////////////////////////////////////////////////////
// API
void Insert(pNode &root, KeyType key);
pNode SearchMinNode(pNode &root);
pLink Node(int item, pLink pLeft, pLink pRight);
pLink InsertNode(pLink p, int item);

///////////////////////////////////////////////////////////////
// 
int main(void)
{
	pLink root = NULL;
    int uBufX[] = {23, 11, 68, 39, 8, 46, 75, 71};
        
    // ����ֵ
    for (int i=0; i<(sizeof(uBufX)/sizeof(int)); i++)
    {
          //vecX.push_back(uBufX[i]);
          InsertNode(root, uBufX[i]);
    }

#if 0   
	// @2017-10-16 ����������
	if(pTmp = SearchMinNode(root))
		cout << pTmp->key << ' ';
	else 
		cout << "Not find Min Node.\r\n";	
#endif

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
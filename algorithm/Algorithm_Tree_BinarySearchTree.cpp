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

///////////////////////////////////////////////////////////////
// 
int main(void)
{
	pNode root = NULL;
	pNode pTmp = NULL;
    KeyType uBufX[] = {23, 11, 68, 39, 8, 46, 75, 71};
    
    //vector<KeyType> vecX;
    
    // ����ֵ
    for (int i=0; i<(sizeof(uBufX)/sizeof(KeyType)); i++)
    {
          //vecX.push_back(uBufX[i]);
          //cout << vecX[i] << " ";
          Insert(root, uBufX[i]);
    }
    cout << endl;	   
	// @2017-10-16 ����������
	if(pTmp = SearchMinNode(root))
		cout << pTmp->key << ' ';
	else 
		cout << "Not find Min Node.\r\n";	
    
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

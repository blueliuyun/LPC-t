///////////////////////////////////////////////////////////////
//
// @2017-10-15  二叉查找树 
// （1）时间复杂度 O(h)，其中 h 是树的高度。 
// （2）空间复杂度 O()
// （3）功能说明 ：a.插入结点，构造二叉树，删除结点，查找最大、最小值。 
//                 b.查找指定结点的前驱和后继。 
///////////////////////////////////////////////////////////////
// 头文件
#include <iostream>
#include <vector>

// 
using namespace std;

// 二叉查找树结点描述
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
	pLink root = NULL;	// 根节点
    int uBufX[] = {23, 11, 68, 39, 8, 46, 75, 71};
        
    // 赋初值
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
// 往二叉查找树中插入结点
// (1) 先根。 
//
void Insert(pNode &root, KeyType key)
{
	// 初始化插入结点
	pNode p = (pNode)malloc(sizeof(stNode));
	p->key = key;
	p->left = p->right = p->parent = NULL;
	// 空树，as root 
	if(root == NULL)
	{
		root = p;
		return;
	}
	
	// 插入到当前结点(root)的左孩子, 树中的每个 key 值的大小不同 
	if((root)->left == NULL && (root)->key > key) 
	{
		p->parent = (root);
		(root)->left = p;
		return;
	}
	// 插入到当前结点(*root)的右孩子
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
		return; // 待插入的值 == root的key，则返回 
}

///////////////////////////////////////////////////////////////
// 
// 查找最小关键字,空树时返回NULL
// (1) 返回值 : pNode 类型的指针
//
pNode SearchMinNode(pNode &root)
{
	if(root == NULL) 
	{
		return 0;
	}	
	if(root->left == NULL)	// 左子树空时 	
	{
		return root;
	}	
	else  					// 左子树非空时 	
	{
		SearchMinNode(root->left);
	}
}

///////////////////////////////////////////////////////////////
// 创建单个Tree结点 2
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
// 插入 2
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
// 删除 - 需考虑 3 中情况：
// (1) 没有孩子节点，即为叶子结点，删除儿子结点。
// (2) 只有 1 个孩子x结点。则可以直接把父结点相应的孩子指针指向
//     该孩子x的独生子，删除儿子结点。
// (3) 有 2 个孩子树（或结点）。可以选择左儿子中的最大元素或右儿
//     子中的最小元素放到待删除结点的位置。习惯上，会选择左儿子中
//     的最大元素。
// 二叉树删除伪代码：
//
//
///////////////////////////////////////////////////////////////
pLink DeleteNode(pLink p, int item)
{
	
}
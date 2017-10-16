///////////////////////////////////////////////////////////////
//
// @2017-10-16  红黑树
// （1）时间复杂度 O()，其中 h 是树的高度。 
// （2）空间复杂度 O()
// （3）功能说明 ：a.插入结点，构造二叉树，删除结点，查找最大、最小值。 
//                 b.查找指定结点的前驱和后继。 
// （4）红黑树是一种平衡二叉树。
//
///////////////////////////////////////////////////////////////
// 头文件
#include <iostream>
#include <vector>

// 
using namespace std;

// 二叉查找树结点描述 
typedef unsigned int KeyType;
typedef struct Node {
	KeyType key;			// 关键字 
	struct Node * left;		// 左孩子指针 
	struct Node * right;	// 右孩子指针 
	struct Node * parent; 	// 指向父节点指针 
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
    
    // 赋初值
    for (int i=0; i<(sizeof(uBufX)/sizeof(KeyType)); i++)
    {
          //vecX.push_back(uBufX[i]);
          //cout << vecX[i] << " ";
          Insert(root, uBufX[i]);
    }
    cout << endl;	   
	// @2017-10-16 遍历二叉树
	if(pTmp = SearchMinNode(root))
		cout << pTmp->key << ' ';
	else 
		cout << "Not find Min Node.\r\n";	
    
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

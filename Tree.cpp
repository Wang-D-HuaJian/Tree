#include<iostream>
#include "Tree.h"
using namespace std;

Tree::Tree()
{
	m_pRoot = new Node();
}


Tree::~Tree()
{
	//DeleteNode(0, NULL);   //删除根节点，即删除一棵树(通下面这种效果一样，取其一就行)
	m_pRoot->DeleteNode();
}

Node *Tree::SearchNode(int nodeIndex)//调用Node的SearchNode（）函数
{
	return m_pRoot->SearchNode(nodeIndex);
}

bool Tree::AddNode(int nodeIndex, int direction, Node *pNode)
{
	Node *temp = SearchNode(nodeIndex);
	if (temp == NULL)
	{
		return false;
	}

	Node *node = new Node();//将要挂载的值取出来
	if (node == NULL)//申请内存失败时
	{
		return false;
	}

	node->index = pNode->index;
	node->data = pNode->data;

	node->pParent = temp;

	if (direction == 0)  //挂载到左节点
	{
		temp->pLChild = node;
	}

	if (direction == 1)  //挂载到右节点
	{
		temp->pRChild = node;
	}
	return true;
}

bool Tree::DeleteNode(int nodeIndex, Node *pNode) //删除节点，该节点的所有延伸子节点都要删除,将删除操作放到节点中操作
{
	Node *temp = SearchNode(nodeIndex);  //首先都要找到目标节点
	if (temp == NULL)
	{
		return false;
	}

	if (pNode != NULL)
	{
		pNode->data = temp->data;
	}
	temp->DeleteNode();  //调用节点的删除操作
	return true;
}


void Tree::PreorderTraversal()  //在树中实现很麻烦，所以移动到节点中进行操作(前序遍历)
{
	m_pRoot->PreorderTraversal();
}

void Tree::InorderTraversal()  //在树中实现很麻烦，所以移动到节点中进行操作（中序遍历）
{
	m_pRoot->InorderTraversal();
}

void Tree::PostorderTraversal()  //在树中实现很麻烦，所以移动到节点中进行操作（后序遍历）
{
	m_pRoot->PostorderTraversal();
}

/*********************************树的数组描述****************************************/
//Tree::Tree(int size, int *pRoot)                                          //创建树
//{
//	m_iSize = size;
//	m_pTree = new int[size];
//	for (int i = 0; i < size; i++)
//	{
//		m_pTree[i] = 0;
//	}
//	m_pTree[0] = *pRoot;
//}
//
//Tree::~Tree()                                               //析构函数
//{
//	delete[]m_pTree;
//	m_pTree = NULL;
//}
//
//int *Tree::SearchNode(int nodeIndex)                          //根据索引nodeIndex寻找节点
//{
//	if (nodeIndex < 0 || nodeIndex >= m_iSize)
//	{
//		return NULL;
//	}
//	if (m_pTree[nodeIndex] == 0)
//	{
//		return NULL;
//	}
//	return &m_pTree[nodeIndex];
//}
//
//bool Tree::AddNode(int nodeIndex, int direction, int *pNode)  //添加节点,direction=0，往左边插入，direction=1,往右边插入
//{
//	if (nodeIndex < 0 || nodeIndex >= m_iSize)//父节点不存在的情况
//	{
//		return false;
//	}
//	if (m_pTree[nodeIndex] == 0) //该数组该位置的值为0，表示这个节点不存在
//	{
//		return false;
//	}
//	if (direction == 0) //决定往左边插入新节点
//	{
//		if (nodeIndex * 2 + 1 >= m_iSize)   //当此处索引大于数组个数，则表示不存在，nodeIndex*2+1表示将要插入的左节点索引
//		{
//			return false;
//		}
//		if (m_pTree[nodeIndex * 2 + 1] != 0) //当要插入的位置的值不为0时，表示此处节点已经存在，不允许再插入
//		{
//			return false;
//		}
//		m_pTree[nodeIndex * 2 + 1] = *pNode; //将值插入左节点（pNode为指针，所以要加*，取值）
//	}
//	if (direction == 1)
//	{
//		if (nodeIndex * 2 + 2 >= m_iSize)   //当此处索引大于数组个数，则表示不存在，nodeIndex*2+2表示将要插入的右节点索引
//		{
//			return false;
//		}
//		if (m_pTree[nodeIndex * 2 + 2] != 0) //当要插入的位置的值不为0时，表示此处节点已经存在，不允许再插入
//		{
//			return false;
//		}
//		m_pTree[nodeIndex * 2 + 2] = *pNode;
//	}
//	return true;
//}
//
//bool Tree::DeleteNode(int nodeIndex, int *pNode)              //删除节点
//{
//	if (nodeIndex < 0 || nodeIndex >= m_iSize)//父节点不存在的情况
//	{
//		return false;
//	}
//	if (m_pTree[nodeIndex] == 0) //该数组该位置的值为0，表示这个节点不存在
//	{
//		return false;
//	}
//	*pNode = m_pTree[nodeIndex];
//	m_pTree[nodeIndex] = 0;//将值赋为0，即删除了节点
//	return true;
//}
//
//void Tree::TreeTraverse()   //遍历数组操作
//{
//	for (int i = 0; i < m_iSize; i++)
//	{
//		cout << m_pTree[i] << " ";
//	}
//}
#ifndef TREE_H
#define TREE_H

/***********************************树的数组描述***********************************************/
//class Tree
//{
//public:
//	Tree(int size, int *pRoot);                                          //创建树
//	~Tree();                                                 // 销毁树
//	int *SearchNode(int nodeIndex);                          //根据索引nodeIndex寻找节点
//	bool AddNode(int nodeIndex, int direction, int *pNode);  //添加节点
//	bool DeleteNode(int nodeIndex, int *pNode);              //删除节点
//	void TreeTraverse();                                     //遍历节点
//
//private:
//	int *m_pTree; //指向一个数组，即树的数组描述
//	int m_iSize;  //用于记录数组的大小
//};


/**********************树的链表描述*************************/
#include "Node.h"
#include "stdlib.h"

class Tree
{
public:
	Tree();                                                   //创建树
	~Tree();                                                  // 销毁树
	Node *SearchNode(int nodeIndex);                           //根据索引nodeIndex寻找节点
	bool AddNode(int nodeIndex, int direction, Node *pNode);  //添加节点
	bool DeleteNode(int nodeIndex, Node *pNode);              //删除节点
	void PreorderTraversal();                                 //前序节点
	void InorderTraversal();                                  //中序遍历
	void PostorderTraversal();                                //后序遍历

private:
	Node *m_pRoot; //树的第一个节点(链表)

};


#endif
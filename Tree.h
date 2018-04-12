#ifndef TREE_H
#define TREE_H

/***********************************������������***********************************************/
//class Tree
//{
//public:
//	Tree(int size, int *pRoot);                                          //������
//	~Tree();                                                 // ������
//	int *SearchNode(int nodeIndex);                          //��������nodeIndexѰ�ҽڵ�
//	bool AddNode(int nodeIndex, int direction, int *pNode);  //��ӽڵ�
//	bool DeleteNode(int nodeIndex, int *pNode);              //ɾ���ڵ�
//	void TreeTraverse();                                     //�����ڵ�
//
//private:
//	int *m_pTree; //ָ��һ�����飬��������������
//	int m_iSize;  //���ڼ�¼����Ĵ�С
//};


/**********************������������*************************/
#include "Node.h"
#include "stdlib.h"

class Tree
{
public:
	Tree();                                                   //������
	~Tree();                                                  // ������
	Node *SearchNode(int nodeIndex);                           //��������nodeIndexѰ�ҽڵ�
	bool AddNode(int nodeIndex, int direction, Node *pNode);  //��ӽڵ�
	bool DeleteNode(int nodeIndex, Node *pNode);              //ɾ���ڵ�
	void PreorderTraversal();                                 //ǰ��ڵ�
	void InorderTraversal();                                  //�������
	void PostorderTraversal();                                //�������

private:
	Node *m_pRoot; //���ĵ�һ���ڵ�(����)

};


#endif
/*******************二叉树的数组表示*************************/
#include "Tree.h"
#include "stdlib.h"
#include<iostream>
using namespace std;

/***************链表表示的树测试***********************/
int main(void)
{
	Node *node1 = new Node();  //定义一个链表节点
	node1->index = 1;
	node1->data = 5;

	Node *node2 = new Node();  //定义一个链表节点
	node2->index = 2;
	node2->data = 8;

	Node *node3 = new Node();  //定义一个链表节点
	node3->index = 3;
	node3->data = 2;

	Node *node4 = new Node();  //定义一个链表节点
	node4->index = 4;
	node4->data = 6;

	Node *node5 = new Node();  //定义一个链表节点
	node5->index = 5;
	node5->data = 9;

	Node *node6 = new Node();  //定义一个链表节点
	node6->index = 6;
	node6->data = 7;

	Tree *tree = new Tree();  //定义一个空节点

	tree->AddNode(0, 0, node1);
	tree->AddNode(0, 1, node2);

	tree->AddNode(1, 0, node3);
	tree->AddNode(1, 1, node4);

	tree->AddNode(2, 0, node5);
	tree->AddNode(2, 1, node6);

	tree->PreorderTraversal();

	cout << endl;

	tree->DeleteNode(0, NULL);

	tree->PreorderTraversal();
	//tree->InorderTraversal();
	//tree->PostorderTraversal();

	delete tree;

	system("pause");
	return 0;


}
















//int main(void)
//{
//	int root = 3;
//	Tree *pTree = new Tree(10, &root);
//	int node1 = 5;
//	int node2 = 8;
//
//	pTree->AddNode(0, 0, &node1);
//	pTree->AddNode(0, 1, &node2);
//
//	int node3 = 2;
//	int node4 = 6;
//
//	pTree->AddNode(1, 0, &node3);
//	pTree->AddNode(1, 1, &node4);
//
//	int node5 = 9;
//	int node6 = 7;
//
//	pTree->AddNode(2, 0, &node5);
//	pTree->AddNode(2, 1, &node6);
//
//	int node = 0;
//	pTree->DeleteNode(6, &node);
//	cout << "ndoe=" << node << endl;
//
//	pTree->TreeTraverse();
//
//	int *p = pTree->SearchNode(2);
//	cout << " " << *p << endl;
//
//	
//
//
//	delete pTree;
//	system("pause");
//	return 0;
//}
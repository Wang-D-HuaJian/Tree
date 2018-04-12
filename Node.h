#ifndef NODE_H
#define NODE_H

class Node
{
public:
	Node();
	Node *SearchNode(int nodeIndex);
	void DeleteNode();
	void PreorderTraversal();                                 //前序节点
	void InorderTraversal();                                  //中序遍历
	void PostorderTraversal();                                //后序遍历

	int index;
	int data;
	Node *pLChild;
	Node *pRChild;
	Node *pParent;

};



#endif
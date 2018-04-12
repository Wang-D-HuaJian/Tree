#include "Node.h"
#include<iostream>
using namespace std;

Node::Node()
{
	index = 0;
	data = 0;
	pLChild = NULL;
	pRChild = NULL;
	pParent = NULL;
}


Node *Node::SearchNode(int nodeIndex)
{
	if (this->index == nodeIndex)
	{
		return this;
	}
	Node *temp = NULL;
	if (this->pLChild != NULL)
	{
		if (this->pLChild->index == nodeIndex)
		{
			return this->pLChild;
		}
		else
		{
			temp = this->pLChild->SearchNode(nodeIndex);
			if (temp != NULL)
			{
				return temp;
			}
		}
	}
	if (this->pRChild != NULL)
	{
		if (this->pRChild->index == nodeIndex)
		{
			return this->pRChild;
		}
		else
		{
			temp = this->pRChild->SearchNode(nodeIndex);
			if (temp != NULL)
			{
				return temp;
			}
		}
	}
	return NULL;
}

void Node::DeleteNode()
{
	if (this->pLChild != NULL)       //删除当前节点的所有左节点
	{
		this->pLChild->DeleteNode();
	}
	if (this->pRChild != NULL)       //删除当前节点的所有右节点
	{
		this->pRChild->DeleteNode();
	}
	if (this->pParent != NULL)       //检查当前节点的父节点，确认当前节点是在父节点的左节点还是右节点，使该指针指向NULL
	{
		if (this->pParent->pLChild == this)
		{
			this->pParent->pLChild = NULL;
		}
		if (this->pParent->pRChild == this)
		{
			this->pParent->pRChild = NULL;
		}
	}
	delete this;  //删除自身节点
}

void Node::PreorderTraversal()  //前序遍历：根节点->左节点->右节点
{
	cout << this->index << " " << this->data << endl;

	if (this->pLChild != NULL)
	{
		this->pLChild->PreorderTraversal();  //递归使访问左右节点变成访问左右子树
	}

	if (this->pRChild != NULL)
	{
		this->pRChild->PreorderTraversal();
	}
}

void Node::InorderTraversal()  //中序遍历：左节点->根节点->右节点
{
	
	if (this->pLChild != NULL)
	{
		this->pLChild->InorderTraversal();
	}

	cout << this->index << " " << this->data << endl;

	if (this->pRChild != NULL)
	{
		this->pRChild->InorderTraversal();
	}
}

void Node::PostorderTraversal()  //后序遍历：左节点->右节点->根节点
{
	if (this->pLChild != NULL)
	{
		this->pLChild->PostorderTraversal();
	}

	if (this->pRChild != NULL)
	{
		this->pRChild->PostorderTraversal();
	}

	cout << this->index << " " << this->data << endl;

}
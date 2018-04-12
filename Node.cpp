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
	if (this->pLChild != NULL)       //ɾ����ǰ�ڵ��������ڵ�
	{
		this->pLChild->DeleteNode();
	}
	if (this->pRChild != NULL)       //ɾ����ǰ�ڵ�������ҽڵ�
	{
		this->pRChild->DeleteNode();
	}
	if (this->pParent != NULL)       //��鵱ǰ�ڵ�ĸ��ڵ㣬ȷ�ϵ�ǰ�ڵ����ڸ��ڵ����ڵ㻹���ҽڵ㣬ʹ��ָ��ָ��NULL
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
	delete this;  //ɾ������ڵ�
}

void Node::PreorderTraversal()  //ǰ����������ڵ�->��ڵ�->�ҽڵ�
{
	cout << this->index << " " << this->data << endl;

	if (this->pLChild != NULL)
	{
		this->pLChild->PreorderTraversal();  //�ݹ�ʹ�������ҽڵ��ɷ�����������
	}

	if (this->pRChild != NULL)
	{
		this->pRChild->PreorderTraversal();
	}
}

void Node::InorderTraversal()  //�����������ڵ�->���ڵ�->�ҽڵ�
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

void Node::PostorderTraversal()  //�����������ڵ�->�ҽڵ�->���ڵ�
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
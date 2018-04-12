#include<iostream>
#include "Tree.h"
using namespace std;

Tree::Tree()
{
	m_pRoot = new Node();
}


Tree::~Tree()
{
	//DeleteNode(0, NULL);   //ɾ�����ڵ㣬��ɾ��һ����(ͨ��������Ч��һ����ȡ��һ����)
	m_pRoot->DeleteNode();
}

Node *Tree::SearchNode(int nodeIndex)//����Node��SearchNode��������
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

	Node *node = new Node();//��Ҫ���ص�ֵȡ����
	if (node == NULL)//�����ڴ�ʧ��ʱ
	{
		return false;
	}

	node->index = pNode->index;
	node->data = pNode->data;

	node->pParent = temp;

	if (direction == 0)  //���ص���ڵ�
	{
		temp->pLChild = node;
	}

	if (direction == 1)  //���ص��ҽڵ�
	{
		temp->pRChild = node;
	}
	return true;
}

bool Tree::DeleteNode(int nodeIndex, Node *pNode) //ɾ���ڵ㣬�ýڵ�����������ӽڵ㶼Ҫɾ��,��ɾ�������ŵ��ڵ��в���
{
	Node *temp = SearchNode(nodeIndex);  //���ȶ�Ҫ�ҵ�Ŀ��ڵ�
	if (temp == NULL)
	{
		return false;
	}

	if (pNode != NULL)
	{
		pNode->data = temp->data;
	}
	temp->DeleteNode();  //���ýڵ��ɾ������
	return true;
}


void Tree::PreorderTraversal()  //������ʵ�ֺ��鷳�������ƶ����ڵ��н��в���(ǰ�����)
{
	m_pRoot->PreorderTraversal();
}

void Tree::InorderTraversal()  //������ʵ�ֺ��鷳�������ƶ����ڵ��н��в��������������
{
	m_pRoot->InorderTraversal();
}

void Tree::PostorderTraversal()  //������ʵ�ֺ��鷳�������ƶ����ڵ��н��в��������������
{
	m_pRoot->PostorderTraversal();
}

/*********************************������������****************************************/
//Tree::Tree(int size, int *pRoot)                                          //������
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
//Tree::~Tree()                                               //��������
//{
//	delete[]m_pTree;
//	m_pTree = NULL;
//}
//
//int *Tree::SearchNode(int nodeIndex)                          //��������nodeIndexѰ�ҽڵ�
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
//bool Tree::AddNode(int nodeIndex, int direction, int *pNode)  //��ӽڵ�,direction=0������߲��룬direction=1,���ұ߲���
//{
//	if (nodeIndex < 0 || nodeIndex >= m_iSize)//���ڵ㲻���ڵ����
//	{
//		return false;
//	}
//	if (m_pTree[nodeIndex] == 0) //�������λ�õ�ֵΪ0����ʾ����ڵ㲻����
//	{
//		return false;
//	}
//	if (direction == 0) //��������߲����½ڵ�
//	{
//		if (nodeIndex * 2 + 1 >= m_iSize)   //���˴���������������������ʾ�����ڣ�nodeIndex*2+1��ʾ��Ҫ�������ڵ�����
//		{
//			return false;
//		}
//		if (m_pTree[nodeIndex * 2 + 1] != 0) //��Ҫ�����λ�õ�ֵ��Ϊ0ʱ����ʾ�˴��ڵ��Ѿ����ڣ��������ٲ���
//		{
//			return false;
//		}
//		m_pTree[nodeIndex * 2 + 1] = *pNode; //��ֵ������ڵ㣨pNodeΪָ�룬����Ҫ��*��ȡֵ��
//	}
//	if (direction == 1)
//	{
//		if (nodeIndex * 2 + 2 >= m_iSize)   //���˴���������������������ʾ�����ڣ�nodeIndex*2+2��ʾ��Ҫ������ҽڵ�����
//		{
//			return false;
//		}
//		if (m_pTree[nodeIndex * 2 + 2] != 0) //��Ҫ�����λ�õ�ֵ��Ϊ0ʱ����ʾ�˴��ڵ��Ѿ����ڣ��������ٲ���
//		{
//			return false;
//		}
//		m_pTree[nodeIndex * 2 + 2] = *pNode;
//	}
//	return true;
//}
//
//bool Tree::DeleteNode(int nodeIndex, int *pNode)              //ɾ���ڵ�
//{
//	if (nodeIndex < 0 || nodeIndex >= m_iSize)//���ڵ㲻���ڵ����
//	{
//		return false;
//	}
//	if (m_pTree[nodeIndex] == 0) //�������λ�õ�ֵΪ0����ʾ����ڵ㲻����
//	{
//		return false;
//	}
//	*pNode = m_pTree[nodeIndex];
//	m_pTree[nodeIndex] = 0;//��ֵ��Ϊ0����ɾ���˽ڵ�
//	return true;
//}
//
//void Tree::TreeTraverse()   //�����������
//{
//	for (int i = 0; i < m_iSize; i++)
//	{
//		cout << m_pTree[i] << " ";
//	}
//}
#include <cstdio>
#include <iostream>
#include "List.h"

ListNode* CreateListNode(int value)
{
	ListNode* node = new ListNode();
	node->m_nKey = value;
	node->m_pNext = nullptr;

	return node;
}

void ConnectListNodes(ListNode* pCurrent, ListNode* pNext)
{
	if(pCurrent == nullptr)
	{
		printf("Connect nullptr...");
		exit(1);
	}

	pCurrent->m_pNext = pNext;
}

void PrintListNode(ListNode* pNode)
{
	if(pNode == nullptr)
		printf("Node is null\n");
	else
		printf("%d\n", pNode->m_nKey);
}

void PrintList(ListNode* pHead)
{
	if(pHead == nullptr)
	{
		printf("list has none node\n");
		return;
	}
	
	printf("Start to print list\n");
	ListNode* list = pHead;
	while(list != nullptr)
	{
		PrintListNode(list);
		list = list->m_pNext;
	}
}

void DestroyList(ListNode* pHead)
{
	ListNode* pNode = pHead;
	while(pNode != nullptr)
	{
		ListNode* next = pNode->m_pNext;
		delete pNode;
		pNode = next;
	}
}

void AddToTail(ListNode** pHead, int value)
{
	ListNode* newNode = CreateListNode(value);

	if(*pHead == nullptr)
		*pHead = newNode;
	else
	{
		ListNode* node = *pHead;
		while(node->m_pNext != nullptr)
			node = node->m_pNext;
		node->m_pNext = newNode; 
	}
}

void RemoveNode(ListNode** pHead, int value)
{
	if(pHead == nullptr || *pHead == nullptr)
	{
		return ;
	}

	ListNode* deleteNode = nullptr;
	if((*pHead)->m_nKey == value)
	{
		deleteNode = *pHead;
		*pHead = (*pHead)->m_pNext;
	}
	else
	{
		ListNode* prev = *pHead;
		while(prev->m_pNext != nullptr && prev->m_pNext->m_nKey != value)
			prev = prev->m_pNext;
		if(prev->m_pNext != nullptr)
		{
			deleteNode = prev->m_pNext;
			prev->m_pNext = prev->m_pNext->m_pNext;
		}
	}
	if(deleteNode != nullptr)
	{
		delete deleteNode;
		deleteNode = nullptr;
	}
}

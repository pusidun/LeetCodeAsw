#include <stdio.h>
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
		return;
	pCurrent->m_pNext = pNext;
}

void PrintListNode(ListNode* pNode)
{
	if(pNode != nullptr)
		printf("%d\n", pNode->m_nKey);
}

void PrintList(ListNode* pHead)
{
	ListNode* list = pHead;
	while(list != nullptr)
	{
		PrintListNode(list);
		list = list->m_pNext;
	}
}

void DestroyList(ListNode* pHead)
{
	while(pHead != nullptr)
	{
		ListNode* next = pHead->m_pNext;
		delete pHead;
		pHead = next;
	}
}

void AddToTail(ListNode** pHead, int value)
{
	ListNode* node = *pHead;
	if(node == nullptr)
		return;
	while(node->m_pNext != nullptr)
		node = node->m_pNext;

	ListNode* newNode = CreateListNode(value);
	node->m_pNext = newNode; 
}

void RemoveNode(ListNode** pHead, int value)
{

}

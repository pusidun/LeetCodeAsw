// struct ListNode
// {
// 	int m_nKey;
// 	ListNode* m_pNext;
// };
#include<stdio.h>
#include "../Utilities/List.h"

ListNode* ReverseList(ListNode* pHead)
{
	ListNode* pPrev = nullptr;
	ListNode* pRevHead = nullptr;
	ListNode* pCurr = pHead;

	while(pCurr!=nullptr)
	{
		ListNode* pNext = pCurr->m_pNext;
		if(pNext == nullptr)
			pRevHead = pCurr;
		pCurr->m_pNext = pPrev;
		pPrev = pCurr;
		pCurr = pNext;
	}

	return pRevHead;
}

//递归实现,返回链表头
//先把最后一个节点和之前节点断开,递归后在当成递归结果的前驱
ListNode* ReverseList_recursion(ListNode* pHead)
{
	if(pHead == nullptr)
		return nullptr;
	if(pHead->m_pNext == nullptr)
	{
		return pHead;
	}

	ListNode* pCurr = pHead;
	ListNode* pPrev = nullptr;
	while(pCurr->m_pNext != nullptr)
	{
		pPrev = pCurr;
		pCurr = pCurr->m_pNext;
	}
	pPrev->m_pNext = nullptr;
	pCurr->m_pNext = ReverseList_recursion(pHead);
	return pCurr;
}

//功能测试 链表包含多节点；链表包含一个节点
void Test1()
{
	ListNode* pHead = CreateListNode(0);
	ListNode* p1 = CreateListNode(1);
	ListNode* p2 = CreateListNode(2);
	ListNode* p3 = CreateListNode(3);
	ListNode* p4 = CreateListNode(4);

	ConnectListNodes(pHead, p1);
	ConnectListNodes(p1, p2);
	ConnectListNodes(p2, p3);
	ConnectListNodes(p3, p4);

	PrintList(pHead);
	ListNode* result1 = ReverseList(pHead);
	PrintList(result1);
	ListNode* result2 = ReverseList_recursion(result1);
	PrintList(result2);
}

//特殊输入测试 nullptr
void Test2()
{
	ListNode* node = nullptr;
	ListNode* result1 = ReverseList(node);
	PrintList(result1);
	ListNode* result2 = ReverseList_recursion(node);
	PrintList(result2);
}

int main()
{
	Test1();
	Test2();

	return 0;
}

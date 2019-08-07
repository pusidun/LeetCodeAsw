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

//递归实现
ListNode* ReverseList_recursion(ListNode* pHead)
{
	if(pHead->m_pNext == nullptr)
		return pHead;
	ListNode* pCurr = pHead;
	ListNode* pNext = ReverseList_recursion(pCurr->m_pNext);
	pNext->m_pNext = pCurr;
}

//功能测试 链表包含多节点；链表包含一个节点
//特殊输入测试 nullptr
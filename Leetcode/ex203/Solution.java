package ex203;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

public class Solution {
	public ListNode removeElements(ListNode head, int val) {
		if(head == null)
			return head;
		while(head.val == val)
		{
			if(head.next == null)
				return null;
			else
				head = head.next;
		}
		ListNode preNode = head;
		ListNode curNode = preNode.next;
		while(curNode != null)
		{
			if(curNode.val != val)
			{
				preNode = curNode;
				curNode = curNode.next;
			}
			else
			{
				preNode.next = curNode.next;
				curNode = curNode.next;
			}
		}
		return head;
	}
	
}

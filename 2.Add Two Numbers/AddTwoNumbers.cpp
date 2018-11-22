/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
        {
            return l2;
        }
        if(l2 == NULL)
        {
            return l1;
        }
        ListNode * pHead = NULL;
        ListNode * pNode = NULL;
        ListNode * p1 = l1;
        ListNode * p2 = l2;
        int flag = 0;
        while(p1 && p2)
        {
            ListNode * pNewNode = new ListNode(0);
            int val = p1->val + p2->val + flag;
            pNewNode->val = (val)%10;
            flag = val > 9 ? 1: 0;
            if(pHead == NULL)
            {
                pHead = pNewNode;
                pNode = pNewNode;
            }
            else
            {
                pNode->next = pNewNode;
                pNode = pNode->next;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        while(p1)
        {
            pNode->next = p1;
            pNode = pNode->next;
            int val = pNode->val + flag;
            pNode->val = (val)%10;
            flag = val > 9? 1: 0;
            p1 = p1->next;
            
        }
        while(p2)
        {
            pNode->next = p2;
            pNode = pNode->next;
            int val = pNode->val + flag;
            pNode->val = (val)%10;
            flag = val > 9? 1: 0;
            p2 = p2->next;
        }
        if(flag > 0)
        {
            ListNode * pNewNode = new ListNode(1);
            pNode->next = pNewNode;
        }
        return pHead;
    }
};
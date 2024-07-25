/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next ==NULL)
        {
            return head;
        }
        int count = 1;
        ListNode* temp= head;
        while(temp->next!=NULL)
        {
            count++;
            temp = temp->next;
        }
        if(k>count)
        {
            k = k%count;
        }
        if(k == count || k==0)
        {
            return head;
        }
        int x = count-k;
        int y = 1;
        temp = head;
        while(y!=x)
        {
            temp = temp->next;
            y++;
        }
        ListNode* temp1 = temp->next;
        temp->next = NULL;
        temp = temp1;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = head;
        head = temp1;
        return head;
    }
};
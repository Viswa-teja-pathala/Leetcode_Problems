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
    ListNode* reverse(ListNode* node)
    {
        ListNode* dummy = NULL;
        ListNode* temp = NULL;
        while(node!=NULL)
        {
            temp = node->next;
            node->next = dummy;
            dummy = node;
            node = temp;

        }
        return dummy;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
        {
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = reverse(slow->next);
        slow = slow->next;

        while(slow!=NULL)
        {
            if(head->val!=slow->val)
            {
                return false;
            }
            head = head->next;
            slow = slow->next;
        }

        return true;
    }
};
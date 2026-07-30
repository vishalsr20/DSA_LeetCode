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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL || left == right)
            return head;
        int size = right - left + 1;
        int i = 1;
        ListNode* temp = head;
        ListNode* prevleft = NULL;
        while(i < left && temp != NULL ){
            prevleft = temp;
            temp = temp->next;
            i++;
        }
        ListNode* start = temp;
        ListNode* prev = NULL;
        ListNode* curr = temp;

        while(i <= right && curr != NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr=next;
            i++;
        }
        temp->next = curr;
        if (prevleft != NULL)
            prevleft->next = prev;
        else
            head = prev;



        

        return head;
    }
};
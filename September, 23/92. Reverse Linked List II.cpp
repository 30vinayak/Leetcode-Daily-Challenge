
// Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // 1 based indexing for left and right
        ListNode *prev = NULL, *cur = head;
        int index = 1;
        while(index < left){
            prev = cur;
            cur = cur -> next;
            index++;
        }
        if(left == right) return head;
        ListNode* front = NULL, *back = cur, *head2 = cur;
        cur = cur -> next;
        while(index < right){
            front = cur -> next;
            cur -> next = back;
            back = cur;
            cur = front;
            index++;
        }
        head2 -> next = front;
        if(prev != NULL){
            prev -> next = back;
            return head;
        }else return back;
    }
};
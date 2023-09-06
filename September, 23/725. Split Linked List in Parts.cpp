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
    int size(ListNode* head){
        int cnt = 0;
        while(head != NULL){
            cnt++;
            head = head -> next; 
        }
        return cnt;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = size(head);
        ListNode *itr = head; 
        vector<ListNode*> groups(k, NULL);
        
        ListNode* grpHead = NULL;
        int grpSize1 = n / k + 1, grpSize2 = grpSize1-1;
        int num1 = n % k, num2 = k - num1;
        int currGrpSize = 0, grpNo = 0;
        ListNode *prev = NULL;
        while(num1 > 0){
            if(currGrpSize == 0){
                grpHead = itr;
            }
            currGrpSize++;
            prev = itr;
            itr = itr -> next;
            if(currGrpSize == grpSize1){
                prev -> next = NULL;
                groups[grpNo] = grpHead;
                grpNo++;
                currGrpSize = 0;
                num1--;
            }
        }
        if(grpSize2 == 0) return groups;
        while(num2 > 0){
            if(currGrpSize == 0){
                grpHead = itr;
            }
            currGrpSize++;
            prev = itr;
            itr = itr -> next;
            if(currGrpSize == grpSize2){
                prev -> next = NULL;
                groups[grpNo] = grpHead;
                grpNo++;
                currGrpSize = 0;
                num2--;
            }
        }
        return groups;
    }
};

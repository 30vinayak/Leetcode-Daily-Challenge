// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

void nextPointer(Node* itr, Node* newItr, int index, map<Node*, int> &mp, map<int, Node*> &newmp){
    while(itr != NULL){
        mp[itr] = index;
        newItr -> next = new Node(itr -> val);
        newItr = newItr -> next;
        itr = itr -> next;
        newmp[index] = newItr;
        index++;
    }
    mp[NULL] = index;
    newmp[index] = NULL;
}
void randomPointer(Node* itr, Node* newitr, map<Node*, int> &mp, map<int, Node*> &newmp){
    while(itr != NULL){
        newitr -> random = newmp[mp[itr->random]];
        itr = itr -> next;
        newitr = newitr -> next;
    }
}
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;
        map<Node*, int> mp;
        map<int, Node*> newmp;
        Node* newHead = new Node(-1);
        nextPointer(head, newHead, 0, mp, newmp);
        randomPointer(head, newHead->next, mp, newmp);
        Node* newHeadCpy = newHead;
        newHead = newHead -> next;
        delete(newHeadCpy);
        return newHead;
    }
};

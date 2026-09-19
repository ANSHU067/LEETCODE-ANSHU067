/*
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
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        Node* ans=new Node(NULL);
        unordered_map<Node*,Node*>mp;
        while(temp){
            mp[temp]=new Node(temp->val);
            temp=temp->next;
        }
        ans->next=mp[head];
        temp=head;
        while(temp){
            ans->next=mp[temp];
            ans=ans->next;
            temp=temp->next;
        }
        ans=mp[head];
        temp=head;
        while(temp){
            if(temp->random==NULL)mp[temp]->random=NULL;
            else mp[temp]->random=mp[temp->random];
            temp=temp->next;
        }
        return ans;
        
    }
};
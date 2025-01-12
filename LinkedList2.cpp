#include <bits/stdc++.h>
using namespace std;

class LLNode {

public:
    int data;
    LLNode *nxt;
};

void push(LLNode **head, int data) 
{
    LLNode *newn = new LLNode();
    newn->data = data;
    newn->nxt = NULL;

    if (*head == NULL) {
        *head = newn;
        return;        
    }
    else {
        LLNode *curr = *head; 
        while (curr->nxt != NULL) {
            curr = curr->nxt;
        }
        curr->nxt = newn;
        return;
    }
}

void print(LLNode *head) {

    LLNode *curr = head;

    while (curr) {
        cout << curr->data << "->";
        curr = curr->nxt;
    }
    cout << endl;
}

void del(LLNode *head) {
    LLNode *curr = head;

    while (curr) {
        LLNode *n = curr;
        curr = curr->nxt;
        delete n;
    }

    
}

bool find(LLNode *head, int data) 
{
    LLNode *curr = head;
    while (curr) {
        if (curr->data == data) {
            return true;
        }
        curr = curr->nxt;
    }
    return false;
}

bool detectLoop(LLNode *head) {

    LLNode *curr = head;
    unordered_set<LLNode *> liset;

    while (curr != NULL) {
        if (liset.find(curr) != liset.end()) {
            return true;
        }
        liset.emplace(curr);
        curr = curr->nxt;
    }
    return false;
}

void ReverseLinkedList(LLNode **hd)
{
    LLNode *prev, *nxt, *curr;
    if (*hd != NULL)
    {
        curr = *hd;
        prev = NULL;
        //nxt = hd->next;

        while (curr != NULL)
        {
            nxt = curr->nxt;
            curr->nxt = prev;
            prev = curr;
            curr = nxt;            
        }
        *hd = prev;
    }
}

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    
};
 
class Solution {

public:

     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (list1 == NULL) {
            return list2;
        }
        if (list2 == NULL) return list1;

        ListNode* A = list1;
        ListNode* B = list2;

        ListNode* retList = new ListNode();
        ListNode* tail = retList;

        while (A != NULL and B != NULL) {
            if (A->val < B->val){
                tail->next = A;
                A = A->next;
            } else {
                tail->next = B;
                B = B->next;
            }
            tail = tail->next;
        }

        if (A != NULL) {
            tail->next = A;
        }
        if (B != NULL) {
            tail->next = B;
        }

        return retList->next;
        
    }
    
    ListNode* mergeKLists(vector<ListNode*>&lists) {

        struct compare {
            bool operator() (struct ListNode *Node1, struct ListNode *Node2) {
                return Node1->val > Node2->val;
            }
        };

        // build the pq
        priority_queue<ListNode*, vector<ListNode*> , compare > pq;
        for (auto node: lists) {
            if (node == NULL) {
                continue;
            }
            pq.push(node);
        }

        // while (!pq.empty() ) {
        //     cout << pq.top()->val << "\n";
        //     pq.pop();
        // }

        if (pq.empty()) {
            return NULL;
        }

        struct ListNode *reslist = new ListNode(0);
        struct ListNode *tail = reslist;

        while (!pq.empty()) {
            struct ListNode *curr = pq.top();
            pq.pop();

            tail->next = curr;
            tail = tail->next;

            if (curr->next != NULL) { 
                pq.push(curr->next);            
            }
        }
        return reslist->next;
       
    }

    void ListNodeDel(ListNode *node) {

        while(node->next != NULL) {
            ListNode *tmp = node;
            
            //cout << node->val << endl;
            node = node->next;
            delete tmp;
        }    
    }
};



int main() 
{
    LLNode *head = NULL;

    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);

    //head->nxt->nxt->nxt->nxt->nxt = head;    

    print(head);
    cout << find(head, 2) << endl;
    cout << detectLoop(head) << endl;
    ReverseLinkedList(&head);
    print(head);
    del(head);

    // 3 lists
    int k = 3;

    // each list has 4 elements
    struct ListNode *node = new ListNode(1);
    node->next =  new ListNode(3);
    node->next->next =  new ListNode(5);
    node->next->next->next =  new ListNode(7);

    struct ListNode *node2 = new ListNode(2);
    node2->next =  new ListNode(4);
    node2->next->next =  new ListNode(6);
    node2->next->next->next =  new ListNode(8);

    struct ListNode *node3 = new ListNode(1);
    node3->next =  new ListNode(9);
    node3->next->next =  new ListNode(10);
    node3->next->next->next =  new ListNode(11);

    vector<ListNode*> vlistNode;
    vlistNode.push_back(node);
    vlistNode.push_back(node2);
    vlistNode.push_back(node3);

    Solution s1;
    ListNode* retList = s1.mergeKLists(vlistNode);

    ListNode* curr = retList; 
    while (curr) {
        cout << curr->val << " " ; 
        curr = curr->next;
    }

    s1.ListNodeDel(retList);



    // each list has 4 elements
    struct ListNode *node4 = new ListNode(1);
    node4->next =  new ListNode(3);
    node4->next->next =  new ListNode(5);
    node4->next->next->next =  new ListNode(7);

    struct ListNode *node5 = new ListNode(2);
    node5->next =  new ListNode(4);
    node5->next->next =  new ListNode(6);
    node5->next->next->next =  new ListNode(8);

    ListNode* retNode = s1.mergeTwoLists(node4, node5);
    ListNode* curr2 = retNode; 
    cout << endl;
    while (curr2) {
        cout << curr2->val << " " ; 
        curr2 = curr2->next;
    }

    
    // s1.ListNodeDel(node2);
    // s1.ListNodeDel(node3);
}
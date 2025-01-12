
#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>


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
    ListNode* mergeKLists(vector<ListNode*>&lists) {

        struct compare {
            bool operator() (struct ListNode *Node1, struct ListNode *Node2) {
                return Node1->val > Node2->val;
            }
        };

        // build the pq
        priority_queue<ListNode*, vector<ListNode*> , compare > pq;
        for (auto node: lists) {
                pq.push(node);
        }

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
};

main() {

    // 3 lists
    int k = 3;

    // each list has 4 elements
    struct ListNode *node = new ListNode(1);
    node->next =  new ListNode(3);
    node->next =  new ListNode(5);
    node->next =  new ListNode(7);

    vector<struct ListNode*> vlistNode();
    vlistNode.push_back(node);



}
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class LLNode {
    public:
    int data;
    LLNode *nxt;
};

void push(LLNode **head, int data) {

    LLNode *node = new LLNode();
    node->nxt = NULL;
    node->data = data;

    if (*head == NULL) {
        *head = node;
        return;
    }
    
    LLNode *curr = *head;
    while (curr->nxt != NULL) {
        curr = curr->nxt;
    }
    curr->nxt = node;
}

void printLL(LLNode *head) {
    LLNode *node = head;
    while (node != NULL) {
        cout << node->data << "->";
        node = node->nxt;
    }
    cout << endl;
}

void reverseLL(LLNode **head) {

    LLNode *prev, *curr, *nxt;

    // if
    curr = *head;
    prev = NULL;
    while (curr != NULL) {
        nxt = curr->nxt;
        curr->nxt = prev;
        prev = curr;
        curr = nxt;
    }
    *head = prev;
}

bool findNode(LLNode *head, int data) {

    LLNode *curr = head;
    while (curr != NULL) {
        if(curr->data == data) return true;
        curr = curr->nxt;
    }
    return false;
}

LLNode * findmiddle(LLNode *node) {

    LLNode *slowPtr = node;
    LLNode *fastPtr = node;

    if(node == NULL) {
        return NULL;
    }
    while(fastPtr != NULL and fastPtr->nxt!=NULL) {
        slowPtr = slowPtr->nxt;
        fastPtr = fastPtr->nxt->nxt;
    }

    // if (slowPtr != NULL )
    //     return slowPtr; 
    return (slowPtr != NULL ) ? slowPtr : NULL;
    
}

bool checkLoop(LLNode *head) {

    unordered_set<LLNode *> llset;
    LLNode *curr = head;

    while(curr !=NULL) {
        if(llset.find(curr) != llset.end()) {
            //found the loop
            return true;
        }
        llset.insert(curr);
        curr = curr->nxt;
    }
    return false;
}

LLNode * mergelist(LLNode *list1, LLNode *list2) {

    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;

    LLNode *A = list1;
    LLNode *B = list2;

    LLNode *dummy = new LLNode;
    LLNode *tail = dummy;
    while(A!= NULL and B!=NULL) {
        if(A->data < B->data) {
            tail->nxt = A;
            A = A->nxt;
        } else {
            tail->nxt = B;
            B=B->nxt;
        }
        tail=tail->nxt;
    }
    if(A!=NULL) {
        tail->nxt = A;
    }    
    else if (B!=NULL) {
        tail->nxt = A;
    }

    return dummy->nxt;
}

class compareNodeEle {
    public:
        bool operator () (LLNode *node1, LLNode *node2) {
            return (node1->data > node2->data);
        }
};

LLNode* mergekList(vector<LLNode *> &llists) {

    // make a priority q and put the 1st node in it
    priority_queue<LLNode *, vector<LLNode *>, compareNodeEle> pq;

    for (auto &list:llists) {
        pq.push(list);
    }
    
    //create dummy list to return 
    LLNode *dummy = new LLNode;
    LLNode *tail = dummy;
    // loop the the pq and pop each val and add to a dummy new list
    while (!pq.empty()) {

        LLNode *curr = pq.top();
        pq.pop();
        tail->nxt = curr;
        tail = tail->nxt;           
        // if the node popped has next add it to pq and keep popping until pq is empty
        if(curr->nxt != NULL) {
            pq.push(curr->nxt);
        }
    }

    LLNode *retList = dummy->nxt;
    // free(dummy); 
    return retList;
}

class Solution {
public:
    string encode(vector<string>& strs) {
        string res;
        for (const string& s : strs) {
            res += to_string(s.size()) + "#" + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            i = j + 1;
            j = i + length;
            res.push_back(s.substr(i, length));
            i = j;
        }
        return res;
    }
};

// https://neetcode.io/solutions/remove-nth-node-from-end-of-list
//  LLNode* removeNthFromEnd(LLNode* head, int n) {

int main() {

    LLNode *node = NULL;
    push(&node, 1);
    push(&node, 2);
    push(&node, 5);
    push(&node, 9);

    LLNode *node2 = NULL;
    push(&node2, 1);
    push(&node2, 3);
    push(&node2, 4);
    push(&node2, 6);

    LLNode *node3 = NULL;
    push(&node3, 1);
    push(&node3, 2);
    push(&node3, 7);
    push(&node3, 8);

    printLL(node);
    // reverseLL(&node);
    printLL(node);
    cout << findNode(node,2) << endl;
    cout << checkLoop(node) << endl;
    LLNode *n = findmiddle(node);
    cout << n->data << endl;
    // LLNode *retNode = mergelist(node, node2);
    // printLL(retNode);
    vector<LLNode *> lists;
    lists.push_back(node);
    lists.push_back(node2);
    lists.push_back(node3);
    LLNode *retList = mergekList(lists);
    printLL(retList);
}
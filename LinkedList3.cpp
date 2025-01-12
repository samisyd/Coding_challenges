#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;


//https://www.geeksforgeeks.org/program-to-implement-singly-linked-list-in-c-using-class/
class LlNode{

    public:
    int data;
    LlNode *next;

    public:
        LlNode(int val) {
            data = val;
            next = NULL;
        }    

};

class LlNodeCompare {
    public:
        bool operator() (LlNode *node1, LlNode *node2) {
            return node1->data > node2->data;
        }
    };

class LList {

    public:
    LlNode *head;
    public:   

        LList() {
            head = NULL;
        }

    
    void append(int data) {

        LlNode *node = new LlNode(data); 
        LlNode *curr = this->head;

        if (curr == NULL) {
            head = node;
            return;
        } 

        while (curr->next != NULL){
            curr = curr->next;
        }
        curr->next = node;
    }

    void print() {
        LlNode *curr = this->head;
        while (curr) {
            cout << curr->data << "->";
            curr = curr->next; 
        }
    }

    bool detectLoop() {

        unordered_set<LlNode *> nodeset;
        LlNode *curr = this->head;

        while (curr != NULL) {

            if (nodeset.find(curr) != nodeset.end()) {
                cout << "Loop detected" << endl;
                cout << "at entry " << curr->data << endl;
                return true;
            }
            nodeset.insert(curr);
            curr = curr->next;
            
        }
        return false;

    }

    bool detectLoop2() {
        LlNode *slowptr = this->head;
        LlNode *fastptr = this->head;

        // if (this->head == NULL) {
        //     return NULL;
        // }

        while (fastptr != NULL && fastptr->next != NULL ) {

            slowptr = slowptr->next;
            fastptr = fastptr->next->next;

            if (slowptr == fastptr) {
                return true;
            }
        }
        return false;

    }

    LlNode * findMiddle() {

        LlNode *slowptr = this->head;
        LlNode *fastptr = this->head;

        if (this->head == NULL) {
            return NULL;
        }

        while (fastptr != NULL && fastptr->next != NULL ) {

            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
        }
        if (slowptr != NULL) {
            return slowptr;
        }
        return NULL;        
    }

    void createLoop() {

        LlNode *curr = this->head;
        LlNode *tmp = NULL;
        while (curr->next) {
            if (curr->data == 3 ) {
                tmp = curr;
            }
            curr = curr->next;
        }
        curr->next = tmp;
    }

    void reverse_list() {

        LlNode *curr = this->head;
        LlNode *prev, *nxt;

        if (this->head == NULL ) {
            return;
        }
        prev = NULL;

        while (curr != NULL) {

            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        this->head = prev;
    }

    LList * merge2listsnew(LList *l1, LList *l2){

        LList *list = new LList();
        list->head = new LlNode(0);
        LlNode *dummy = list->head;

        //LlNode *A = l1->head!=NULL ? l1->head : NULL;
        //LlNode *B = l2->head!=NULL ? l2->head : NULL;
        LlNode *A = l1->head;
        if(A == NULL) {
            return l2;
        }
        LlNode *B = l2->head;
        if(B == NULL) {
            return l1;
        }

        while(A!= NULL and B!=NULL) {

            if (A->data < B->data) {
                dummy->next = A;
                A = A->next;
            } else {
                dummy->next = B;
                B = B->next;
            }
            dummy = dummy->next;
        }

        if (A != NULL) {
            dummy->next = A;
        }
        if (B != NULL) {
            dummy->next = B;
        }
        
        LlNode *tmp = list->head;
        list->head = list->head->next;
        free (tmp);
        return list;

    }

    LList* mergeKLists(vector<LlNode *>&lists) {
        
        if (lists.size() == 0) return NULL;
        
        //priority_queue<LlNode * , vector<LlNode *>, LlNode*()> pq;
        priority_queue<LlNode * , vector<LlNode *>, LlNodeCompare> pq; 
        for (auto lnode : lists) {  
            if (lnode == NULL) continue;
            pq.push(lnode);
        }

        if (pq.size() == 0) return NULL;

        LList *retList = new LList();
        retList->head = new LlNode(0);
        LlNode * dummy = retList->head;

        while (!pq.empty()) {
            
            LlNode *curr = pq.top();
            pq.pop();

            dummy->next = curr;
            dummy = dummy->next;

            if (curr->next) {
                pq.push(curr->next);
            }
        }

        LlNode *tmp = retList->head;
        retList->head = retList->head->next;
        return retList;

    }
};

main()
{
    LList llist = LList();
    //llist->head = new LlNode(1);
    llist.append(1);
    llist.append(2);
    llist.append(4);
    llist.append(7);
    llist.append(9);
    llist.print();
    cout << endl;
    //llist.createLoop();
    //llist.print();
    cout << llist.detectLoop2() << endl;
    LlNode *middle = llist.findMiddle();
    cout << middle->data << endl;
    // llist.reverse_list();
    // llist.print();

    
    LList llist2 = LList();
    //llist->head = new LlNode(1);
    llist2.append(1);
    llist2.append(3);
    llist2.append(5);
    llist2.append(7);
    llist2.append(8);
    llist2.print();
    cout << endl; 
    
    //LList *retList = llist.merge2listsnew(&llist, &llist2);
    //retList->print();

    LList llist3 = LList();
    //llist->head = new LlNode(1);
    llist3.append(1);
    llist3.append(3);
    llist3.append(6);
    llist3.append(8);
    llist3.append(10);
    llist3.print();
    cout << endl; 

    vector<LlNode *> lists ={llist.head, llist2.head, llist3.head};
    LList* retList = llist.mergeKLists(lists);
    cout << "merge k lists" << endl;
    retList->print();
}



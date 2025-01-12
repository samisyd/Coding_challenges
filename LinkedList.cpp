#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

struct LinkedList {
    int data;
    LinkedList *next;
};

void push(LinkedList **headptr, int data) {

    LinkedList *listptr = new LinkedList();
    listptr->data = data;
    listptr->next = NULL;

    if (*headptr == NULL) {
        *headptr = listptr;
        return;
    } 

    LinkedList *last = *headptr;
    //while ( (*headptr)->next != NULL) {
    while ( last->next != NULL) {
        last = last->next;
    }  

    last->next = listptr;
    return;
}

bool detectloop(LinkedList *myListHead) {

    unordered_set<LinkedList *> s;
    LinkedList *curr = myListHead;

    while (curr != NULL) {

        if (s.find(curr) != s.end()) {
                printf("loop starts here %d",curr->data);
                return true;
        }
        s.insert(curr);
        curr = curr->next;  
    }
}

int main() {

    struct LinkedList *myListHead = NULL;

    push(&myListHead, 1);
    push(&myListHead, 2);
    push(&myListHead, 3);
    push(&myListHead, 4);
    push(&myListHead, 5);

    // create loop
    myListHead->next->next->next->next->next = myListHead; 
    if (detectloop(myListHead)) {
        printf("found loop");
    }
    else {
        cout << "no loop" << endl;
    }
}
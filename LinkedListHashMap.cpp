#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Llist {
    protected:
        int key;
        int val;
        Llist *next;

    public:
    Llist(int key, int val): key(key), val(val), next(NULL) {}
    Llist(): key(-1), val(-1), next(NULL) {}

    void put(int key, int value) {

        // cout << "inside put " << this->key << endl;
        Llist *curr = this;
        while (curr->next != NULL) {
            if (curr->next->key == key) {
                curr->next->val = value;
                return;
            }
            curr = curr->next;
        }
        curr->next = new Llist(key, value); 
        // cout << "added new val" << curr->next->val << endl;
    }

    int get(int key) {
        Llist *curr = this;
        while(curr->next  ) {
            if(curr->next->key == key) {
                return curr->next->val;
            }
            curr = curr->next;
        }
        return -1;
    }
    void remove(int key) {
        Llist *curr = this;
        while(curr->next) {
            if(curr->next->key == key) {
               Llist *tmp = curr->next;
               curr->next = curr->next->next;
               delete tmp;
               return; 
            }
            curr = curr->next;
        }
    }

    void print() {
        Llist *curr = this;
        // cout << "this val" << this->val << endl;

        while(curr->next) {
            cout << "this val" << curr->next->val << endl;
            curr = curr->next;
        }

    }
};

class Hashmap{

    private:
    vector<Llist *> mmap;

    public:

    //constructor
    Hashmap() {
        mmap.resize(100);
        for(auto &bucket:mmap) {
            bucket = new Llist();
        }

        // if (mmap[0] == NULL) {
        //     cout << "inside constructor mmap[0] is null" ;
        // } else {
        //     cout << "not null" ;
        // }
    }

    //hashkey
    int hashkey(int key) {
        return key % mmap.size();
    }
    
    // put a val
    void put(int key, int value) 
    {
        // cout << "inside put " << key << endl;
        int val = hashkey(key);
        // cout << "hashkey val is " << val << endl;
        Llist *lnode = mmap[hashkey(key)];
        if(lnode == NULL) {
           cout << "lnode is null" << endl; 
           return;
        }
         
        lnode->put(key, value);
        // lnode->print();
    }
    int get(int key) {
        Llist *node = mmap[hashkey(key)];
        node->get(key);
    }
    void remove(int key) {
        Llist *node = mmap[hashkey(key)];
        node->remove(key);
    }

};

int main() {

    Hashmap map =  Hashmap();
    cout << "created new hashmap" << endl;
    map.put(200, 2001);
    map.put(201, 2003);
    map.put(100, 2004);
    map.put(300, 2002);
    map.put(301, 2006);
    
    cout << map.get(200) << endl;
    cout << map.get(201) << endl;
    map.put(200, 2007);
    cout << map.get(200) << endl;
    cout << map.get(100) << endl;
    map.remove(200);
    cout << map.get(200) << endl;
    cout << map.get(300) << endl;
    cout << map.get(301) << endl;
}
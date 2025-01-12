#include<stdio.h>
#include<stdlib.h>
#include <bits/stdc++.h>
#include <stack>
using namespace std;

// #Day1
// # Day 1:
// # Problem 1 http://bit.ly/3k2oz2h
// # Problem 2 http://bit.ly/3S0zyWs
// # Day 2:
// # Problem 1 http://bit.ly/3k2oFXH
// # Problem 2 http://bit.ly/3YP0Y3T done - merge sorted array
// # Day 3:
// # Problem 1 http://bit.ly/3YLeG7P
// # Problem 2 http://bit.ly/3xmO4yk

// # Day2
// # Problem 1 http://bit.ly/3xkple6
// # Problem 2 http://bit.ly/3Yx18xe
// # Day 5:
// # Problem 1 http://bit.ly/3xp5SZI
// # Problem 2 http://bit.ly/3HYbe2Z
// # Day 6:
// # Problem 1 http://bit.ly/3HUQLw2
// # Problem 2 http://bit.ly/3XwCfQM
// # Problem 3 http://bit.ly/3IoXDDh

// # Day 3:
// # Problem 1 http://bit.ly/3Ilr7B1
// # Problem 2 http://bit.ly/3lC6dFZ
// # Problem 3 http://bit.ly/3IyjiJz
// # Day 8:
// # Problem 1 http://bit.ly/3lADgdw
// # Problem 2 http://bit.ly/3Iq7PM3
// # Day 9:
// # Problem 1 http://bit.ly/3I4nIWS
// # Problem 2 http://bit.ly/3K3lSIx

// # Day 4
// # Problem 1 http://bit.ly/3xksCtU -  Done preorder
// # Problem 2 http://bit.ly/3IojxGF -  inorder
// # Problem 3 http://bit.ly/3E7e30C -  postorder
// # Day 11:
// # Problem 1 http://bit.ly/3E2WL4P -  level order
// # Problem 2 http://bit.ly/3lEMa9F -  Depth
// # Problem 3 http://bit.ly/3k1rYhV -  Symmetric tree
// # Day 12:
// # Problem 1 http://bit.ly/3YNgkWE - Done Invert binary tree
// # Problem 2 http://bit.ly/3YtCVI0

// #Day 5
// # Problem 1 http://bit.ly/3S6itL6 - Done - Search BST
// # Problem 2 http://bit.ly/3Io0uwb
// # Day 14:
// # Problem 1 http://bit.ly/3Xsu87T
// # Problem 2 http://bit.ly/3E7IIuW
// # Problem 3 http://bit.ly/3YztLtC



//Definition for a binary tree node.

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
    
    public:
    TreeNode* searchBST(TreeNode* root, int val) {

        if (root == NULL || root->val == val ) {
            return root;
        }

        TreeNode *curr = root;
        while (curr != NULL) {

            if (val < curr->val ) {
                if ( curr->left!=NULL && curr->left->val == val) {
                    return curr->left;
                }
                curr = curr->left; 
            } else {
                if ( curr->right!=NULL && curr->right->val == val) {
                    return curr->right;
                }
                curr = curr->right;
            }
        }
        return NULL;
    }

    TreeNode* invertTree(TreeNode* root) {

        if (root == NULL) {
            return root;
        }
        TreeNode *tmp;
        tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int k = m+n-1;
        int i=m-1, j=n-1;
        
        while (i>=0 && j>=0) {

            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i-=1;  
            } else {
                nums1[k] = nums2[j];
                j-=1;
            }
            k-=1;
        }

        while (j >= 0) {
            nums1[k] = nums2[j];
            k-=1;
            j-=1;  
        }   
    }

    vector<int> preorderTraversal2(TreeNode* root) {

        vector<int>ans;
        if(root==NULL)
        {
            return ans;
        }
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* temp=st.top();
            ans.push_back(temp->val);
            st.pop();
            if(temp->right!=NULL) st.push(temp->right);
            if(temp->left!=NULL) st.push(temp->left);
        }
        return ans;
    }

    
    vector<int> ans;
    void preorderTraversalhelper(TreeNode* node) {

        if (node == NULL) {
            return;
        }
        ans.push_back(node->val);
        preorderTraversalhelper(node->left);
        preorderTraversalhelper(node->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {       
        if (root == NULL) {
            return ans;
        }
        preorderTraversalhelper(root);
        return ans;
    }

    
	string reverseWords(string s) {
        
       // Temporary vector to store all words
        vector<string> tmp;
        string str = "";
        for (int i = 0; i < s.length(); i++) 
        {        
            // Check if we encounter space 
            // push word(str) to vector
            // and make str NULL
            if (s[i] == ' ') 
            {
                tmp.push_back(str);
                str = "";
            }
    
            // Else add character to 
            // str to form current word
            else
                str += s[i];
        }
        
        // Last word remaining,add it to vector
        tmp.push_back(str);

        string ans="";
        for(int i=tmp.size()-1;i>=0;i--){
            ans+=tmp[i];
            if(i!=0)
                ans+=" ";
        }
        return ans;
    }

    string reverseWords2(string s) {

        stack<string> stak;
        string str = "";
        for(int i=0; i<s.size(); i++){
            if(s[i]== ' '){
                if(!str.empty())
                    stak.push(str);
                str = "";
            }
            else{
                str += s[i];
            }
        }
        stak.push(str);
        string ans = "";
        while(!stak.empty()){
            if(!ans.empty())
                ans +=' ';
            ans += stak.top();
            stak.pop();
        }
        return ans;
    }

     bool isValid(string s) {
        stack<char> st;
        for(auto c:s)
        {
            if(c=='(' or c=='{' or c=='[') { 
                st.push(c); 
            }
            else {
                if(st.empty() or (st.top()=='(' and c!=')') or (st.top()=='{' and c!='}') 
                            or (st.top()=='[' and c!=']')) 
                            return false;
                st.pop();
            }
        }
        return st.empty();
    }

    string encode(vector<string> strv) {

        string retst;

        for (auto str : strv) {

            int len = str.length();
            retst += to_string(len) + "#" + str;
        } 
        return retst;
    }

    vector<string> decode(const string &estr) {

        int len = estr.length();
        cout << "entered str "<< estr << endl;
        int i =0 ,j = 0;
        vector<string> retstrl;

        while (i < len) {

            j = i;
            while(estr[j] != '#') {
                j++;
            }
            int stlen = stoi(estr.substr(i, j-i));            
            string str = estr.substr(j+1, stlen);            
            retstrl.push_back(str);
            i = j+1 + stlen;
        }

        return retstrl;
    }

    //https://leetcode.com/problems/largest-rectangle-in-histogram
    int largestRectangleArea(vector<int>& heights) {

        stack<pair<int,int>> mstack;
        int maxv = 0;

        // if increasing push in stack and if decrease pop
        int  area =0;
        int start =0;
        for (int i=0; i<heights.size(); i++) {
            start = i;

            while(!mstack.empty() && mstack.top().second > heights[i]) {
                    pair<int,int> p = mstack.top();
                    mstack.pop();
                    // calculate length
                   int  area = p.second * (i-p.first);
                   maxv = max(maxv, area);
                   //update index with the pairs index
                   start = p.first;
            }
            pair<int,int> mpair(start, heights[i]); 
            mstack.push(mpair);
        }
         
        while (mstack.size()) {
            // calc area of each
            pair<int,int> p = mstack.top();
            mstack.pop();
            area = p.second * (heights.size() - p.first);
            maxv = max(maxv, area);
            
        }
        return maxv;
    }

    /*
    Given array of strings, group anagrams together (same letters diff order)
    Ex. strs = ["eat","tea","tan","ate","nat","bat"] -> [["bat"],["nat","tan"],["ate","eat","tea"]]

    Count chars, for each string use total char counts (naturally sorted) as key

    Time: O(n x l) -> n = length of strs, l = max length of a string in strs
    Space: O(n x l)
    */

   private:
   string getkey(string &str){

        vector<int> charVal(26);
        for(auto ch : str) {
            charVal[ch - 'a'] += 1;
        }
        string key = "";
        for(int i=0; i<charVal.size(); i++) {            
            key.append(to_string(charVal[i]));            
        }
        cout << "str is " << str << endl;
        cout << key << endl;
        // string mystr = "";
        // for(int i=0; i<charVal.size(); i++) {
        //     if (charVal[i] > 0) {
        //         int val = i + 'a';
        //         cout << "char val is " << char(val) << endl;
        //         mystr += char(val);
        //     }
        // }
        // cout << "mykey is %s " <<  mystr << endl;
        return key;
    }

    public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> hmap;
        //vector<string> *itr;        
        for(auto stri : strs ) {

            string key = getkey(stri);
            hmap[key].push_back(stri);            
        } 

        vector<vector<string>> retVec;
        for (auto it=hmap.begin(); it!=hmap.end(); it++) {
            retVec.push_back(it->second);
        }

        return retVec;
    }
};

int main() {

    Solution s;

    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    TreeNode *tmp  = s.searchBST(root, 5);
    if (tmp != NULL) {
        cout << " NODE PRESENT " ;     
    } else {
        cout << "NODE not PRESENT ";
    } 

    string mstr = s.reverseWords("samina is mad");
    cout << mstr << endl;

    vector<string> strs = {"sam","har$i","ka#l"};
    
    string estr =  s.encode(strs);
    cout << "encoded str is " << estr << endl;

    vector<string> strs2 = s.decode(estr);
    for (auto s:strs2){
        cout << s << " ";
    }
    cout << endl;


    pair<int,int> pr;
	pr.first = 1; 
	pr.second = 10; 

    stack<pair<int,int>> st;
    st.push({1,10});
    st.push({2,20});

    int ht, wd;
    while(!st.empty()) {

            ht = st.top().first;
            wd = st.top().second;
            cout << "ht is " << ht;  
            cout << "wd is" << wd << endl; 
            st.pop();
    }

    vector<string> instrs = {"eeat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ret =  s.groupAnagrams(instrs);
    for (auto vec: ret) {
        for (auto str:vec) {
            cout << str << " ";
        }
        cout << endl;
    }

    
// C++ program to demonstrate the creation of descending
// order set container // ordered set
    int A = 71;
    cout << "val of A is " << char(A) << endl; 

     set<int, greater<int> > s1;
    s1.insert(10);
    s1.insert(5);
    s1.insert(12);
    s1.insert(4);
 
    for (auto i : s1) {
        cout << i << ' ';
    }
    // returns 12 10 5 4 
    return 0;

    set<int, greater<int> >::iterator itr;
    cout << "\nThe set s1 is : \n";
    for (itr = s1.begin(); itr != s1.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;

    // assigning the elements from s1 to s2
    set<int> s2(s1.begin(), s1.end());

    // remove all elements up to 30 in s2
    cout << "\ns2 after removal of elements less than 30 "
            ":\n";
    s2.erase(s2.begin(), s2.find(30));
    for (itr = s2.begin(); itr != s2.end(); itr++) {
        cout << *itr << " ";
    }

}
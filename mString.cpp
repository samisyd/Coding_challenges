#include <string>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class mString {

    private:
    char *m_buffer;
    unsigned int m_size;

public:
    mString(const char *str){

        int len =  strlen(str);
        m_buffer = new char[len+1];
        // for (int i =0; i<len; i++) {
        //     m_buffer[i] = str[i];
        // }
        memcpy(m_buffer, str, len);
        m_buffer[len] = 0;
        m_size = len;
        cout << m_buffer;

    }

    // "The memcpy() function is used to copy a specified number of bytes from 
    // one memory to another. Whereas, the strcpy() function is used to copy
    //  the contents of one string into another. The memcpy() function operates on
    //   a memory instead of a value. Whereas, strcpy() function works on value, not memory."

    //Copy constructor - if you want to disble copying
    //mString(const mString &str) = delete; 
    //else if u allow it 
    mString(const mString &otherstr) : m_size(otherstr.m_size) 
    {
        m_buffer = new char[m_size+1];
        memcpy(m_buffer, otherstr.m_buffer, m_size+1 );
        cout << m_buffer;
    }
    
    char& operator[](unsigned int index)
    {
        return m_buffer[index];
    }

    ~mString() {

        delete [] m_buffer;
    }

    friend ostream &operator<<(ostream &stream, const mString &str);
};

ostream& operator<<(ostream& stream, const mString &str){

    stream << str.m_buffer;
    return stream;

}
void PrintString(const mString &str)
{
    cout << str << endl;
}   

# /*
#     Design algorithm to encode/decode: list of strings <-> string

#     Encode/decode w/ non-ASCII delimiter: {len of str, "#", str}

#     Time: O(n)
#     Space: O(1)
# */
string encode(const vector<string>& strs) {

    string mystr ="";
    for (auto stri:strs) {
        
        int lens = stri.length();

        mystr += to_string(lens) + '#' + stri;    
    }
    return mystr;
}

vector<string> decode(const string &mstr) {

    int i=0, j=0;
    int m = mstr.length();
    vector<string> retstr;
    while(i <m) {

        j = i;
        while (mstr[j] != '#') {
            j++;
        }
        int slen = stoi(mstr.substr(i, j-i));
        string stri = mstr.substr(j+1,  slen);
        cout << stri << endl;
        retstr.emplace_back(stri);
        i = j+1+slen;
    }
    return retstr;
}

/*
    Given unsorted array, return length of longest consecutive sequence
    Ex. nums = [100,4,200,1,3,2] -> 4, longest is [1,2,3,4]

    Store in hash set, only check for longer seq if it's the beginning

    Time: O(n)
    Space: O(n)
*/

 int longestConsecutive(vector<int>& nums) {

    unordered_set<int> s1(nums.begin(), nums.end());

    int long_s = 0;
    int max_seq = 1;
    
    for (auto &n:nums) {
        if (s1.find(n-1) == s1.end() ) {
            int long_s = 1;

            while (s1.find(n+long_s) != s1.end()) {
                long_s += 1;
                max_seq = max(max_seq, long_s);
                cout << "long_s " << long_s << " " << n+long_s << endl; 
            }            
        }
    } 
    return max_seq;
 }

void prodOfSelf(const vector<int> &arr) {

    int len = arr.size();
    vector<int> arr1(len,1);
    vector<int> arr2(len,1); 
    vector<int> res(len,1); 

    for (int i=1; i<len; i++) {

        arr1[i] = arr[i-1] * arr1[i-1];
    } 

    for (int i=len-1-1; i>=0; i--) {
        arr2[i] = arr[i+1] * arr2[i+1];
        cout << arr2[i] << " " << i << " " << endl ;
    }
    cout << endl;
  
    for (int i=0; i<len; i++) {
        res[i] = arr1[i] * arr2[i];
    }

    for (int i=0; i<len; i++) {
        cout << res[i] << " " ;
    }
    cout << endl;
    
    // for(auto it = arr.end() - 1; it>=arr.begin();it--) {
	// 	cout << *it << " "; 
	// }
}

void reverseString(char *string) {

    char *begin = string;
    char *end = string;

    printf("in revere string");
    if (end == '\0') {
        printf("returning as end is 0 ");
        return;
    }
    while (*end != '\0') {
        end++;
    } 
    end--; // last is \0 so skip that

    printf("begin is  ", *begin);
    printf("end  is  ", *end);

    char tmp;
    while (begin < end) {
        tmp = *begin;
        *begin = *end;
        *end = tmp;

        cout << "begin is" << *begin << endl;
        begin++;
        end--;  
    }

    cout << string << endl;
}

int main() {

    mString str = "sam";
    mString str2(str);

    str2[2] = 'c';
    cout << str << endl;
    cout << str2 << endl;
    cout << "my str"; 

    PrintString(str);

    vector<int> myarr = {1,2,3,4};
    prodOfSelf(myarr);

    vector<int> nums = {100, 2,200, 1,3,4}; 
    cout << "long seq is " << longestConsecutive(nums) <<endl;

    vector<string> strs = {"sam","har$i","ka#l"};
    
    string estr =  encode(strs);
    cout << "encoded str is " << estr << endl;
    
    vector<string> resstrs = decode(estr);
    vector<string>::iterator stri;
    for (stri = resstrs.begin(); stri!=resstrs.end(); stri++) {
        cout << *stri << endl;
    }




    vector<int> mv={3,5,2,8};
	//sort(a, a+4);
	sort(mv.begin(), mv.end());
    
    for (auto st = mv.begin(); st != mv.end(); ++st)
        cout << ' ' << *st;
    cout << '\n';
    //cin.get();

    string first[] = { "Sachin", "Rakesh", "Sandeep", "Serena" }; 
    string second[] = { "Vaibhav", "Sandeep", "Rakesh", "Neha" };
    
    int n = sizeof(first) / sizeof(first[0]);
    sort(first, first + n);    
    sort(second, second + n);
    
    vector<string> v(10);
    vector<string>::iterator it, st;

     // Using default operator<
    it = set_intersection(first, first + n, second, second + n, v.begin());
 
    cout << "Students attending both the classes only are :\n";
    for (st = v.begin(); st != it; ++st)    
        cout << ' ' << *st;
    cout << '\n';

    vector<string> v2(10);
    vector<string>::iterator it2, st2;
    // Using default function
    it2 = set_union(first, first + n, second, second + n, v2.begin());

    cout << "all Students attending  the classes  are :\n";
    for (st2 = v2.begin(); st2 != it2; ++st2)   
        cout << ' ' << *st2;
    cout << '\n';

    vector<int> x = {1, 3, 5, 6, 7, 4, 8};
    vector<int> y = {1, 2, 3, 5, 7, 8};
 
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    vector<int>::iterator it3, st3;
    vector<int> resv(13);
    it3 = set_intersection(x.begin(), x.end(), y.begin(), y.end(), resv.begin());
    
    for (st3 = resv.begin(); st3 != it3; ++st3)
        cout << ' ' << *st3;
    cout << '\n';

    vector<int> resv2;
    set_intersection(x.begin(), x.end(), y.begin(), y.end(), inserter(resv2, resv2.begin()));
    for (auto &k:resv2) {
        cout << k << " ";
    }
    cout << endl;
    cout << "done";

    // set_difference
//     First array : 5 10 15 20 25
// Second array : 10 20 30 40 50
// Using default comparison,
// The difference has 3 elements : 5 15 25

//set_symmetric_difference
// The symmetric difference has 6 elements:  5 15 25 30 40 50

    //return 0;
    
cout << endl;
 char s[5]={'s','a','\0','c','h'};
    char p[5];
    char t[5];
    int i;
    strcpy(p,s);
    memcpy(t,s,5);
    for(i=0;i<5;i++)
        printf("%c",p[i]);
        printf("\n");
    for(i=0;i<5;i++)
        printf("%c",t[i]);



    char nstr[] = "sami";
    reverseString(nstr);

    return 0;
}

// // strcpy stops when it encounters a NUL ('\0') character, memcpy does not. You do not see the effect here, as %s in printf also stops at NUL.


// The main difference is that memcpy() always copies the exact number of bytes you specify; strcpy(), on the other hand, will copy until it reads a NUL (aka 0) byte, and then stop after that.
/*


    Performance-wise, it should really depend on the compiler and the platform. I've tested 
    on two different environments and got these results: On Linux ARMv7L, memcpy was
     1.5x faster than strcpy. However, on Linux x86_64, using GCC 13.1.1 and Clang 16.0.5,
      strncpy and strcpy both was faster than memcpy by 10% (maybe because of a modern 
      compiler implementation?). Your mileage may vary, so you should test it yourself. – 
    MAChitgarha
    Jul 26, 2023 at 10:40



*/
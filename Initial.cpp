#include <bits/stdc++.h>
#include<iostream>
#include<array> // for array, at()
#include<vector>
#include<map>
#include<set>
#include<string.h>
#include<stdio.h>
//#include <ctype.h>
using namespace std;

// print_array function will print the values of an array
void print_array(int *number, int size) {
  for (int i = 0; i < size; i++) {
    cout << number[i] << " ";
  }
  cout << endl;
}

// modify_array function
void modify_array(int number[], int size) {
  // Traverse array
  for (int i = 0; i < size; i++) {
    // If value less tha 50 set it to -1
    if (number[i] < 50)
      number[i] = -1;
  }
  cout << "Values of array inside the function:" << endl;
  // Call print_array function 
  print_array(number,size);
}

// Migratory bird
//    vector<int> vec = {1, 4, 4, 5, 3};

// int migratoryBirds2(vector<int> &arr) {

//     unordered_map<int, int> mapBirds;
//     int max=0;
//     for (auto i : arr) {
//         mapBirds[i]++

//     }

// }


int main()
{
    //int arr[] = {1,2,3,4,5};
    array<int, 5> arr = {1,2,3,4,5};

    int arr2[5];

    // will print 5 * 4 bytes for each int = 20
    int m = sizeof(arr);

    printf("printing array size %d and m %d", arr.size(), m);
    cout << endl;

    for (auto i:arr)
    {
        cout << i << " ";
    }
    cout << endl;
    for (auto it = arr.begin(); it< arr.end(); it++)
    {
        cout << *it << " ";
    }

    cout << "the second way" << endl;
    for (int i=0; i<5; i++)
    {
        cout << arr[i] << " ";
    }

    int n = sizeof(arr2);
    printf("printing size of arr2 is %d \n", n);
    int sum = 0;
    arr2[0] = 1;
    for (int i=1; i<5; i++) 
    {
        sum = sum+arr2[i-1];
        arr2[i] = sum;
        cout << arr2[i] << " " ;
    }

    cout << endl;

    string s = "abcdrf";
    for(auto c:s) {
        cout << c << " ";
    }

    vector<int> nums = {2,11,5,7};
    int sumv = 9;
    unordered_map<int,int> mmap2;

    for (int i=0; i<nums.size(); i++) {

        if ( (mmap2.find(nums[i])) != mmap2.end()) {
            printf("the 2 vals are %d %d", nums[mmap2[nums[i]]], nums[i]);
            break;
        } 
        mmap2[sumv - nums[i]] = i;
    }
    cout << endl;
    // Migratory bird
    vector<int> vec = {1, 4, 4, 5, 3};

    map<int, int>hashm;
    m = vec.size();
    int max = 0;

    for(int i=0; i<m; i++)
    {
        hashm[vec[i]]++;
        cout << hashm[vec[i]] << endl;
        if (hashm[vec[i]] > hashm[max]) {
            max = vec[i];
        }
    }

    cout << max << endl;

    unordered_map<int, int> mmapbirds;
    int max2 = 0;
    for (auto i: vec) {
        mmapbirds[i]++;
        cout << mmapbirds[i] << endl;
        if(mmapbirds[i] > mmapbirds[max2]) {
            max2 = i;
        }        
    }
    cout << "max val is: " << max2 <<endl;

    // given N elements, print all elements in sorted order 
	// input 
	// n = 6 
	/// 6 6 3 2 3 5 

	// output 
	// 2 3 3 5 6 6 
    printf("multiset test");
    cout << endl;
    array<int, 6> marr = {6, 6, 3, 2, 3, 5};

    multiset<int> ms;
    for (auto i:marr) {
        ms.insert(i);
    }

    for (auto i:ms){
        cout << i << " ";
    }

    printf("program to get only numbers \n");    
    printf("now testing the sum of digits \n");
    char str2[]="12a4ebc";

    m = strlen(str2);
    int sum2 = 0;
    
    int noofcON =0;
    int noofNon = 0;
    char mystr[20] = "";
    int k = 0;
    
    for (int i =0; i<m; i++) {

        //printf("val is %c", str2[i]);
        if (str2[i] >='0' && str2[i] <='9' ) {
            //if (isdigit(str2[i]) != 0) { // this too works
            //printf("printing ",str2[i] - 0);
            sum2 = sum2 + int(str2[i] - '0');
            mystr[k] = str2[i];
            k++;
            //printf("my str %s, orig %c", mystr, str2[i]);
        }
        if (isalpha(str2[i]) != 0) {

            if (str2[i] == 'a' || str2[i] == 'e' || str2[i] == 'i' || str2[i] == 'o' || str2[i] == 'u' ) {
                noofcON +=1;
            }
            else {
                noofNon +=1;
            }
        }
        
    }
    printf(" sum is %d string is %s \n",sum2, mystr);
    printf("noofcON %d nonNon %d",noofNon, noofNon );

    if (noofNon > noofNon) {
        printf("Good string");
    }
    else {
        printf("Bad string");
    }




  // Initialize variables
  int decimal = 10, binary = 0;
  int remainder, product = 1;
  // Prints value of decimal
  cout << "Decimal Number = " << decimal << endl;
  // while block
  /*Checks if the value of `decimal` is not equal to `0`. 
  If yes, then execute line No. 17 to 21.
  If no, then execute line No. 23.
  */
  while (decimal != 0) {
    remainder = decimal % 2;
    binary = binary + (remainder * product);
    decimal = decimal / 2;
    product *= 10;
  }
  // while exit
  cout << "Binary Number = " << binary << endl;

    string  bs="";
  int decimal2 = 10;
  while (decimal2 != 0) {
    remainder = decimal2 % 2;
    decimal2 = decimal2 / 2;
    bs += to_string(remainder);
  }
  cout << "bin is " << bs << endl;
  

  //arrays are passed by reference

  // Initialize size of an array
  int size = 8;
  // Initialize values of array
  int number[size] = {67, 89, 56, 43, 29, 15, 90, 67};

  cout << "Values of array before function call:" << endl;
  // Call print_array function
  print_array(number,size);
  // Call modify_array function
  modify_array(number, size);
  cout << "Values of array after function call:" << endl;
  // Call print_array function
  print_array(number,size);

    
    // initialize container
    multimap<int, int> mp;
  
    // insert elements in random order
    mp.emplace(2, 30);
    mp.emplace(1, 40);
    mp.emplace(2, 60);
    mp.emplace(2, 20);
    mp.emplace(1, 50);
    mp.emplace(4, 50);
  
    // prints the elements
    cout << "\nThe multimap is : \n";
    cout << "KEY\tELEMENT\n";
    for (auto itr = mp.begin(); itr != mp.end(); itr++)
        cout << itr->first << "\t" << itr->second << endl;
  
    
    multimap<int, string> mmap1;
        //mmap1.insert(pair <int, string> (1, "Lisa"));
    //mmap1.insert(pair <int, string> (3, "Marge"));
    mmap1.emplace(1, "Bart2");
    mmap1.emplace(2, "Bart3");
    mmap1.emplace(2, "Bart4");
    mmap1.insert({3, "Bart5"});
    mmap1.emplace(4, "Bart3");
    
    multimap<int, string>::iterator it3;
    for(it3 = mmap1.begin(); it3 != mmap1.end(); it3++){
        cout << "Key : " << it3->first << endl;
        cout << "Value : " << it3->second << endl;
    }
    
    vector<int> v1 = {2,5,3,5};
    int maxi = *max_element(v1.begin(), v1.end());
    
    cout << maxi << endl;

     int v[] = { 9, 4, 7, 2, 5, 10, 11, 12, 1, 3, 13 };
 
    // Finding the maximum value between the third and the
    // ninth element
    size = 11;
    int* i1;
    i1 = max_element(v, v+11);
    
    cout << *i1 << endl;

    int i = 1;
    string c = to_string(1);

    cout << c << endl;

    
    int A[] = {1,2,3,4};
    int size2 = sizeof(A)/sizeof(A[0]);
    printf("size id %d \n", size2);
    for (int i=0; i<4; i++) {
        printf("address %d \n", &A[i]);
        printf("address %d \n", A + i);
        printf("address %d \n" , A[i]);
        printf("address %d \n", *(A + i));
    } 

}


/*
HW - given n elements print the ele that occurs max no of times

Sets are implemeted as binary search tree internaally. They can be ordered or unordered set.

map - ordered/sorted and unique keys
map<int, int> mymap;
map<int, pair<int,int>>
unordered map - unordered and unnique keys
#include <unordered_set>
#include <unordered_map>


multimap - orderred/sorted and duplicate keys
// as the values are different
    multimap<int, string> mmap1;

Stack are impemented using stack or a linked list
video - how to implement stack using arrays

Queue - front, push, pop all operations are constant time operations

Set implements Red-Black tree behind
Map implements AVL tree

Doubly ended queue - push and pop in both dirctions 
dequeue<int> dq;

Lists in C++ is implemented as a doubly linked list internally
Vector is more efficient

 max size of array = 10 power 6 inside the main()
where as if we declare globally we can declare max size of array = 10 power 7 

    sets in c++ always stores numbers in ascending order. so when 
    inserting in set it is lograthamic insertions. Ordereed collection
	arr[] = {2, 5, 2, 1, 5} // 3 unique elements -> {1. 2. 5}
 
	set<int> st; 
	int n;
	cin >> n;
	for(int i = 0;i<n;i++) {
		int x;
		cin >> x; 
		st.insert(x); 
	}
 
	cout << st.size(); 
 
	// st -> {1, 2, 5}
	// erase functionality 
	// log n 
	st.erase(st.begin()); // st.erase(iterator) // st -> {2, 5}
 

*/








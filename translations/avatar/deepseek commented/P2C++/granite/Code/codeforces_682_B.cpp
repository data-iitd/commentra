
#include <bits/stdc++.h>  // Include necessary libraries
using namespace std;

// Define input functions
#define I(a) for(auto &a:vec_input())  // Read a list of integers
#define IS() string s;cin>>s;  // Read a single string
#define IN() int n;cin>>n;  // Read an integer
#define IF() float f;cin>>f;  // Read a float

// Read the number of elements
IN();

// Read the list of elements
vector<int> vec_input(){vector<int> v;int num;while(cin>>num){v.pb(num);}return v;}

// Initialize variables
int f=1;  // Flag variable
sort(vec_input().begin(),vec_input().end());  // Sort the list
int c=0;  // Counter variable

// Iterate through the list to find the maximum number of unique elements
for(auto i:vec_input()){
    if(i>c){
        c++;  // Increment the counter if the current element is greater than the counter
    }
}

// Print the result
cout<<c+1<<endl;  // Print the maximum number of unique elements


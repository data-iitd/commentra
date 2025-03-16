#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
#include <cctype>
#include <complex>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
#include <cctype>
#include <complex>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;

// Function to solve the problem
bool solve(){
    // Initialize variables to track the longest string and its count
    int maxsize=0;
    int maxcnt=0;
    int ans_num; // Index of the longest string
    int ans_num2; // Index of the most frequent string
    vector<string> str_v; // Vector to store input strings
    
    // Variable to read input strings
    string in;
    while(cin>>in){
        str_v.push_back(in); // Store the input string in the vector
        if(maxsize < in.size()){ // Check if the current string is the longest so far
            maxsize = in.size(); // Update the length of the longest string
            ans_num = str_v.size()-1; // Store the index of the longest string
        }
    }
    
    // Count occurrences of each string and find the most frequent string
    for(int i=0;i<str_v.size();i++){
        int cnt=0;
        for(int j=0;j<str_v.size();j++){
            if(str_v[i] == str_v[j]) cnt++; // Count occurrences of the current string
        }
        if(maxcnt < cnt){ // Check if the current string is the most frequent so far
            maxcnt = cnt; // Update the count of the most frequent string
            ans_num2 = i; // Store the index of the most frequent string
        }
    }
    
    // Output the most frequent and the longest string
    cout<< str_v[ans_num2]<< " "<< str_v[ans_num]<< endl;
    
    return true; // Return true indicating success
}

// Main function to set precision and call the solve function
int main(){
    cout.setf(ios::fixed);
    cout.precision(10);
    solve();

    return 0;
}


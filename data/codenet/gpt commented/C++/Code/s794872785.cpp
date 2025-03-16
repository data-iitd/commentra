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

// Function to solve the problem of finding the longest and most frequent string
bool solve(){
    // Initialize variables to track the maximum size of strings and their counts
    int maxsize = 0; // To store the length of the longest string
    int maxcnt = 0;  // To store the count of the most frequent string
    int ans_num;     // Index of the longest string
    int ans_num2;    // Index of the most frequent string
    vector<string> str_v; // Vector to store input strings
    
    string in; // Variable to hold each input string
    // Read strings from standard input until EOF
    while(cin >> in){
        str_v.push_back(in); // Add the string to the vector
        // Check if the current string is longer than the previously recorded maximum
        if(maxsize < in.size()){
            maxsize = in.size(); // Update the maximum size
            ans_num = str_v.size() - 1; // Update index of the longest string
        }
    }
    
    // Loop through the vector to find the most frequent string
    for(int i = 0; i < str_v.size(); i++){
        int cnt = 0; // Counter for occurrences of the current string
        // Count how many times the current string appears in the vector
        for(int j = 0; j < str_v.size(); j++){
            if(str_v[i] == str_v[j]) cnt++; // Increment count if a match is found
        }
        // Check if the current count is greater than the previously recorded maximum count
        if(maxcnt < cnt){
            maxcnt = cnt; // Update the maximum count
            ans_num2 = i; // Update index of the most frequent string
        }
    }
    
    // Output the most frequent string and the longest string
    cout << str_v[ans_num2] << " " << str_v[ans_num] << endl;
    
    return true; // Indicate successful execution
}

int main(){
    // Set output format to fixed-point notation with 10 decimal places
    cout.setf(ios::fixed);
    cout.precision(10);
    solve(); // Call the solve function to process input and output results

    return 0; // Indicate successful program termination
}


#include <bits/stdc++.h>
using namespace std;

// Function to read a line of input and strip whitespace
string input() {
    string s;
    getline(cin, s);
    return s;
}

// Function to read an integer from input
int INT() {
    return stoi(input());
}

// Function to read a list of integers from input
vector<int> MAP() {
    string s = input();
    vector<int> v;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
            v.push_back(s[i] - '0');
        }
    }
    return v;
}

// Function to read a list of integers and return it as a list
vector<int> LIST() {
    string s = input();
    vector<int> v;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
            v.push_back(s[i] - '0');
        }
    }
    return v;
}

// Function to read multiple lists of integers and return them as tuples
vector<vector<int>> ZIP(int n) {
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = LIST();
    }
    return v;
}

// Set the recursion limit to a high value
void set_recursion_limit(int n) {
    stack_limit::set_size(n);
}

// Define a constant for infinity
const int INF = 1e9;

// Define a constant for the modulo value
const int mod = 1e9 + 7;

// Read the number of elements
int N = INT();

// Read the list of integers
vector<int> A = LIST();

// Remove consecutive duplicates from the list
A.erase(unique(A.begin(), A.end()), A.end());

// Update N to the new length of A after removing duplicates
N = A.size();

// Initialize the index and answer counter
int i = 1;
int ans = 0;

// Loop through the list to count the number of peaks and valleys
while (i < N - 1) {
    // Check if the current element is a peak or a valley
    if (A[i - 1] < A[i] > A[i + 1] || A[i - 1] > A[i] < A[i + 1]) {
        ans += 1;  // Increment the answer for each peak/valley found
        i += 1;    // Skip the next element to avoid double counting
    }
    i += 1;  // Move to the next element
}

// Print the total count of peaks and valleys plus one
cout << ans + 1 << endl;


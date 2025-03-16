
#include <bits/stdc++.h>
using namespace std;

// Define a lambda function to read an integer input
auto num_inp = [](){ int x; cin >> x; return x; };

// Define a lambda function to read a list of integers from input
auto arr_inp = [](){ int n; cin >> n; vector<int> a(n); for(int i = 0; i < n; ++i) cin >> a[i]; return a; };

// Define a lambda function to read a space-separated list of integers as a map object
auto sp_inp = [](){ int n; cin >> n; map<int, int> m; while(n--) { int x; cin >> x; m[x]++; } return m; };

// Read the input from the first line of the standard input, sort it, and convert it to a list of integers
auto a = sorted(vector<int>(sp_inp().begin(), sp_inp().end()));

// Check if any element in the list 'a' is not divisible by the first element of 'a'
// If all elements are divisible, print the first element; otherwise, print -1
cout << (all_of(a.begin(), a.end(), [a](int x){ return x % a[0] == 0; })? a[0] : -1) << endl;


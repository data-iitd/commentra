
#include <bits/stdc++.h>
using namespace std;

// Define lambda functions for input handling
// num_inp: takes a single input as an integer
// arr_inp: takes a list input where each element is an integer
// sp_inp: takes a list input where each element is an integer, space-separated

auto num_inp = [](){ int n; cin >> n; return n; };
// This line reads a single integer input from the user

auto arr_inp = [](){ int n; cin >> n; vector<int> a(n); for(int i = 0; i < n; i++) cin >> a[i]; return a; };
// This line reads a list input from the user, where each element is an integer

auto sp_inp = [](){ int n; cin >> n; vector<int> a(n); for(int i = 0; i < n; i++) cin >> a[i]; return a; };
// This line reads a list input from the user, where each element is an integer, space-separated

// Read input from file instead of user input
auto a = sorted(vector<int>(istream_iterator<int>(cin), {}));
// This block reads the input from the file, converts each line to a list of integers,
// and sorts the list of integers

// Find the largest number that leaves a remainder when divided by any number in the list
cout << (a[0] == 0? -1 : a[0]) << endl;
// This block calculates the answer and prints it

Translate the above Python code to Java and end with comment "
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Define lambda functions for input handling
auto I = []() {
    vector<int> v;
    for (int i; cin >> i;)
        v.push_back(i);
    return v;
};
auto IS = []() {
    string s;
    getline(cin, s);
    return s;
};
auto IN = []() {
    int i;
    cin >> i;
    return i;
};
auto IF = []() {
    double d;
    cin >> d;
    return d;
};

// Read the number of elements
int n = IN();

// Read the list of integers
vector<int> l = I();

// Initialize a variable to track unique counts
int f = 1;
sort(l.begin(), l.end());

// Initialize a counter for unique elements
int c = 0;

// Iterate through the sorted list to count unique elements
for (int i : l)
    if (i > c)
        c++;

// Output the total count of unique elements
cout << c + 1 << endl;


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
    vector<int> v;
    string s;
    while (getline(cin, s) && s!= "
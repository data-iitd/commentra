#include <bits/stdc++.h>
using namespace std;

// Function to read a line from standard input and remove trailing whitespace
string rs() {
    string s;
    getline(cin, s);
    return s.substr(0, s.find_last_not_of(" \n\r\t") + 1);
}

// Function to read an integer from standard input
int ri() {
    return atoi(rs().c_str());
}

// Function to read a line from standard input and return a list of strings
vector<string> rs_() {
    string s;
    vector<string> v;
    while (getline(cin, s) && s!= "
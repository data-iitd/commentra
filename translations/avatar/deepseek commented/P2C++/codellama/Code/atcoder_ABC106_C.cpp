
#include <bits/stdc++.h>
using namespace std;

// Functions to read input more efficiently
vector<int> LI() {
    vector<int> v;
    string s;
    getline(cin, s);
    stringstream ss(s);
    int x;
    while (ss >> x) {
        v.push_back(x);
    }
    return v;
}
vector<int> LI_() {
    vector<int> v = LI();
    for (int i = 0; i < v.size(); i++) {
        v[i]--;
    }
    return v;
}
vector<double> LF() {
    vector<double> v;
    string s;
    getline(cin, s);
    stringstream ss(s);
    double x;
    while (ss >> x) {
        v.push_back(x);
    }
    return v;
}
vector<string> LS() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    vector<string> v;
    while (ss >> s) {
        v.push_back(s);
    }
    return v;
}
int I() {
    string s;
    getline(cin, s);
    return stoi(s);
}
double F() {
    string s;
    getline(cin, s);
    return stod(s);
}
string S() {
    string s;
    getline(cin, s);
    return s;
}
void pf(string s) {
    cout << s << flush;
}

// Main function to execute the program
int main() {
    string s = S();  // Read the input string
    int k = I();  // Read the integer k
    int l = 0;  // Initialize a counter for leading '1's
    for (int i = 0; i < s.length(); i++) {  // Loop through each character in the string
        if (s[i] != '1') {  // Check if the character is not '1'
            break;  // Exit the loop if a non-'1' character is found
        }
        l++;  // Increment the counter for each '1' found
    }
    if (l >= k) {  // Check if the number of leading '1's is greater than or equal to k
        return 1;  // Return 1 if true
    }
    return s[l];  // Return the character at the position of the first non-'1' character
}

// Print the result of the main function
pf(to_string(main()));


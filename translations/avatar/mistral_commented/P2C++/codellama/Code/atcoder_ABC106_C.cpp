#######
# Code
#######

# Including necessary libraries
#include <bits/stdc++.h>

// Defining constants
const int inf = 1000000000;
const double eps = 1.0 / 1000000000;
const int mod = 1000000007;

// Defining direction vectors
const int dd[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
const int ddn[8][2] = { { -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 }, { 0, -1 }, { -1, -1 } };

// Function to read a list of integers from standard input
vector<int> LI( ) {
    vector<int> v;
    string s = "";
    int x;
    while (cin >> x) {
        v.push_back(x);
    }
    return v;
}

// Function to read a list of integers from standard input, subtracting 1 from each element
vector<int> LI_( ) {
    vector<int> v = LI( );
    for (int i = 0; i < v.size( ); i++) {
        v[i] -= 1;
    }
    return v;
}

// Function to read a list of floats from standard input
vector<float> LF( ) {
    vector<float> v;
    string s = "";
    float x;
    while (cin >> x) {
        v.push_back(x);
    }
    return v;
}

// Function to read a single line from standard input as a list of strings
vector<string> LS( ) {
    string s = "";
    getline(cin, s);
    vector<string> v = split(s);
    return v;
}

// Function to read a single integer from standard input
int I( ) {
    int x;
    cin >> x;
    return x;
}

// Function to read a single float from standard input
float F( ) {
    float x;
    cin >> x;
    return x;
}

// Function to read a single string from standard input
string S( ) {
    string s = "";
    getline(cin, s);
    return s;
}

// Function to print a string with a newline character at the end
void pf(string s) {
    cout << s << endl;
}

// Function to print a list of integers
void print_list(vector<int> v) {
    for (int i = 0; i < v.size( ); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Function to print a list of floats
void print_list(vector<float> v) {
    for (int i = 0; i < v.size( ); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Function to print a list of strings
void print_list(vector<string> v) {
    for (int i = 0; i < v.size( ); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Function to print a list of integers with a newline character at the end
void print_listn(vector<int> v) {
    for (int i = 0; i < v.size( ); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Function to print a list of floats with a newline character at the end
void print_listn(vector<float> v) {
    for (int i = 0; i < v.size( ); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Function to print a list of strings with a newline character at the end
void print_listn(vector<string> v) {
    for (int i = 0; i < v.size( ); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Function to print a list of integers with a newline character at the end
void print_listn(vector<int> v, int n) {
    for (int i = 0; i < v.size( ); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Function to print a list of floats with a newline character at the end
void print_listn(vector<float> v, int n) {
    for (int i = 0; i < v.size( ); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Function to print a list of strings with a newline character at the end
void print_listn(vector<string> v, int n) {
    for (int i = 0; i < v.size( ); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Function to print a list of integers with a newline character at the end
void print_listn(vector<int> v, string s) {
    for (int i = 0; i < v.size( ); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Function to print a list of floats with a newline character at the end
void print_listn(vector<float> v, string s) {
    for (int i = 0; i < v.size( ); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Function to print a list of strings with a newline character at the end
void print_listn(vector<string> v, string s) {
    for (int i = 0; i < v.size( ); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Function to print a list of integers with a newline character at the end
void print_listn(vector<int> v, int n, string s) {
    for (int i = 0; i < v.size( ); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Function to print a list of floats with a newline character at the end
void print_listn(vector<float> v, int n, string s) {
    for (int i = 0; i < v.size( ); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Function to print a list of strings with a newline character at the end
void print_listn(vector<string> v, int n, string s) {
    for (int i = 0; i < v.size( ); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Function to print a list of integers with a newline character at the end
void print_listn(vector<int> v, string s, string s2) {
    for (int i = 0; i < v.size( ); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Function to print a list of floats with a newline character at the end
void print_listn(vector<float> v, string s, string s2) {
    for (int i = 0; i < v.size( ); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Function to print a list of strings with a newline character at the end
void print_listn(vector<string> v, string s, string s2) {
    for (int i = 0; i < v.size( ); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Function to print a list of integers with a newline character at the end
void print_listn(vector<int> v, int n, string s, string s2) {
    for (int i = 0; i < v.size( ); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Function to print a list of floats with a newline character at the end
void print_listn(vector<float> v, int n, string s, string s2) {
    for (int i = 0; i < v.size( ); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Function to print a list of strings with a newline character at the end
void print_listn(vector<string> v, int n, string s, string s2) {
    for (int i = 0; i < v.size( ); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Function to print a list of integers with a newline character at the end
void print_listn(vector<int> v, string s, string s2, string s3) {
    for (int i = 0; i < v.size( ); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Function to print a list of floats with a newline character at the end
void print_listn(vector<float> v, string s, string s2, string s3) {
    for (int i = 0; i < v.size( ); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Function to print a list of strings with a newline character at the end
void print_listn(vector<string> v, string s, string s2, string s3) {
    for (int i = 0; i < v.size( ); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Function to print a list of integers with a newline character at the end
void print_listn(vector<int> v, int n, string s, string s2, string s3) {
    for (int i = 0; i < v.size( ); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Function to print a list of floats with a newline character at the end
void print_listn(vector<float> v, int n, string s, string s2, string s3) {
    for (int i = 0; i < v.size( ); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Function to print a list of strings with a newline character at the end
void print_listn(vector<string> v, int n, string s, string s2, string s3) {
    for (int i = 0; i < v.size( ); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Function to print a list of integers with a newline character at the end
void print_listn(vector<int> v, string s, string s2, string s3, string s4) {
    for (int i = 0; i < v.size( ); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Function to print a list of floats with a newline character at the end
void print_listn(vector<float> v, string s, string s2, string s3, string s4) {
    for (int i = 0; i < v.size( ); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Function to print a list of strings with a newline character at the end
void print_listn(vector<string> v, string s, string s2, string s3, string s4) {
    for (int i = 0; i < v.size( ); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Function to print a list of integers with a newline character at the end
void print_listn(vector<int> v, int n, string s, string s2, string s3, string s4) {
    for (int i = 0; i < v.size( ); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Function to print a list of floats with a newline character at the end
void print_listn(vector<float> v, int n, string s, string s2, string s3, string s4) {
    for (int i = 0; i < v.size( ); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Function to print a list of strings with a newline character at the end
void print_listn(vector<string> v, int n, string s, string s2, string s3, string s4) {
    for (int i = 0; i < v.size( ); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Function to print a list of integers with a newline character at the end
void print_listn(vector<int> v, string s, string s2, string s3, string s4, string s5) {
    for (int i = 0; i < v.size( ); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Function to print a list of floats with a newline character at the end
void print_listn(vector<float> v, string s, string s2, string s3, string s4, string s5) {
    for (int i = 0; i < v.size( ); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Function to print a list of strings with a newline character at the end
void print_listn(vector<string> v, string s, string s2, string s3, string s4, string s5) {
    for (int i = 0; i < v.size( ); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Function to 
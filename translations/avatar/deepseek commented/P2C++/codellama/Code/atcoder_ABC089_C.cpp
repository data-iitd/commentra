
#include <bits/stdc++.h>
using namespace std;

// Function to read a single line of input
string input() {
    string s;
    getline(cin, s);
    return s;
}

// Function to convert input to an integer
int INT() {
    return stoi(input());
}

// Function to read a map of integers
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

// Function to convert input to a list of integers
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

// Function to create combinations from a list of tuples
vector<vector<int>> ZIP(int n) {
    vector<vector<int>> v;
    for (int i = 0; i < n; i++) {
        v.push_back(MAP());
    }
    return v;
}

// Set recursion limit to prevent recursion errors
void set_recursion_limit() {
    stack_t ss;
    int limit = 1000000000;
    get_stack(ss, limit);
}

// Define constants
const int INF = 1e9 + 7;
const int mod = 1000000007;

// Import numpy for numerical operations
#include <numpy/ndarrayobject.h>

// Read the number of strings
int N = INT();

// Read the list of strings
vector<string> S = vector<string>(N);
for (int i = 0; i < N; i++) {
    S[i] = input();
}

// List of characters that can be selected
vector<string> march = {"M", "A", "R", "C", "H"};

// Initialize a list to count occurrences of each character in 'march'
vector<int> march_lis = vector<int>(5, 0);

// Count the occurrences of characters in 'march' in the list of strings
for (int i = 0; i < N; i++) {
    if (S[i][0] == 'M' || S[i][0] == 'A' || S[i][0] == 'R' || S[i][0] == 'C' || S[i][0] == 'H') {
        march_lis[march.index(S[i][0])] += 1;
    }
}

// Initialize the answer variable
int ans = 0;

// Calculate the number of combinations of three elements from march_lis
for (int i = 0; i < march_lis.size(); i++) {
    for (int j = i + 1; j < march_lis.size(); j++) {
        for (int k = j + 1; k < march_lis.size(); k++) {
            ans += march_lis[i] * march_lis[j] * march_lis[k];
        }
    }
}

// Print the final answer
cout << ans << endl;


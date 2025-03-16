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

// Function to read a map of integers from input
vector<int> MAP() {
    vector<int> v;
    string s;
    getline(cin, s);
    stringstream ss(s);
    int x;
    while (ss >> x) {
        v.push_back(x);
        if (ss.peek() == ',')
            ss.ignore();
    }
    return v;
}

// Function to read a list of integers from input
vector<int> LIST() {
    return MAP();
}

// Function to read multiple lists of integers and zip them together
vector<vector<int>> ZIP(int n) {
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
        v[i] = LIST();
    return v;
}

// Set the recursion limit to a high value
const int N = 1000000007;

// Define constants for infinity and modulo
const int INF = 1000000000;
const int mod = 1000000007;

// Read the number of strings to process
int N = INT();

// Read N strings from input
vector<string> S(N);
for (int i = 0; i < N; i++)
    cin >> S[i];

// Define the target characters to count
string march = "MARCH";

// Initialize a list to count occurrences of each target character
vector<int> march_lis(5);

// Count the occurrences of each character in the input strings
for (string s : S) {
    if (s[0] == 'M' || s[0] =='m')
        march_lis[0]++;
    if (s[0] == 'A' || s[0] == 'a')
        march_lis[1]++;
    if (s[0] == 'R' || s[0] == 'r')
        march_lis[2]++;
    if (s[0] == 'C' || s[0] == 'c')
        march_lis[3]++;
    if (s[0] == 'H' || s[0] == 'h')
        march_lis[4]++;
}

// Initialize the answer variable to store the result
int ans = 0;

// Calculate the number of ways to choose 3 different characters from the counts
for (int x : march_lis) {
    for (int y : march_lis) {
        for (int z : march_lis) {
            if (x + y + z == 3)
                ans += x * y * z;
        }
    }
}

// Print the final answer
cout << ans << endl;

// 
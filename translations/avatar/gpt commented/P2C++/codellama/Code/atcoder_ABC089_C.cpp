
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
map<int, int> MAP() {
    map<int, int> m;
    string s = input();
    stringstream ss(s);
    int x;
    while (ss >> x) {
        m[x]++;
    }
    return m;
}

// Function to read a list of integers from input
vector<int> LIST() {
    string s = input();
    stringstream ss(s);
    vector<int> v;
    int x;
    while (ss >> x) {
        v.push_back(x);
    }
    return v;
}

// Function to read multiple lists of integers and zip them together
vector<vector<int>> ZIP(int n) {
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = LIST();
    }
    return v;
}

// Set the recursion limit to a high value
const int MAX_RECURSION_DEPTH = 1000000000;

// Define constants for infinity and modulo
const int INF = 1000000000;
const int mod = 1000000007;

// Import numpy for numerical operations (though not used in the code)
#include <numpy/ndarrayobject.h>

// Read the number of strings to process
int N = INT();

// Read N strings from input
vector<string> S = vector<string>(N);
for (int i = 0; i < N; i++) {
    S[i] = input();
}

// Define the target characters to count
vector<string> march = {"M", "A", "R", "C", "H"};

// Initialize a list to count occurrences of each target character
vector<int> march_lis = vector<int>(5, 0);

// Count the occurrences of each character in the input strings
for (string s : S) {
    if (s[0].upper() == "M") {
        march_lis[0]++;
    } else if (s[0].upper() == "A") {
        march_lis[1]++;
    } else if (s[0].upper() == "R") {
        march_lis[2]++;
    } else if (s[0].upper() == "C") {
        march_lis[3]++;
    } else if (s[0].upper() == "H") {
        march_lis[4]++;
    }
}

// Initialize the answer variable to store the result
int ans = 0;

// Calculate the number of ways to choose 3 different characters from the counts
for (int x : march_lis) {
    for (int y : march_lis) {
        for (int z : march_lis) {
            if (x != y && y != z && z != x) {
                ans += x * y * z;
            }
        }
    }
}

// Print the final answer
cout << ans << endl;


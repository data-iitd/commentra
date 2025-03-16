#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <cstring>

using namespace std;

#define ll long long
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set
#define mod 1000000007

// Function to read a line of input and strip whitespace
string input() {
    string line;
    getline(cin, line);
    return line.strip();
}

// Function to read an integer from input
int INT() {
    return stoi(input());
}

// Function to read a list of integers from input
vector<int> LIST() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> numbers;
    int num;
    while (ss >> num) {
        numbers.pb(num);
    }
    return numbers;
}

// Function to read multiple lists of integers and return them as tuples
vector<vi> ZIP(int n) {
    vector<vi> result;
    for (int i = 0; i < n; ++i) {
        result.pb(LIST());
    }
    return result;
}

// Set the recursion limit to a high value
#undef _GLIBCXX_DEBUG

// Define a constant for infinity
const long long INF = LLONG_MAX;

// Read the number of elements
int N = INT();

// Read the list of integers
vector<int> A = LIST();

// Remove consecutive duplicates from the list
vector<int> B;
for (int i = 0; i < A.size(); ++i) {
    if (i == 0 || A[i] != A[i - 1]) {
        B.pb(A[i]);
    }
}

// Update N to the new length of B after removing duplicates
N = B.size();

// Initialize the index and answer counter
int i = 1;
int ans = 0;

// Loop through the list to count the number of peaks and valleys
while (i < N - 1) {
    // Check if the current element is a peak or a valley
    if (B[i - 1] < B[i] && B[i] > B[i + 1] || B[i - 1] > B[i] && B[i] < B[i + 1]) {
        ans += 1; // Increment the answer for each peak/valley found
        i += 1;   // Skip the next element to avoid double counting
    }
    i += 1; // Move to the next element
}

// Print the total count of peaks and valleys plus one
cout << ans + 1 << endl;


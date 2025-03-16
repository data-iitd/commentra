#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <unordered_map>
#include <set>
#include <stack>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <numeric>
#include <limits.h>
#include <functional>
#include <bitset>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <tuple>
#include <climits>
#include <map>
#include <iterator>
#include <cassert>

using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mod 1000000007
#define INF LLONG_MAX
#define NINF LLONG_MIN
#define endl "\n"

// Function to read an integer from standard input
int readInt() {
    int n;
    cin >> n;
    return n;
}

// Function to read a string from standard input
string readString() {
    string s;
    cin >> s;
    return s;
}

// Function to read a list of integers from standard input
vector<int> readList() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    return a;
}

// Function to read a list of strings from standard input
vector<string> readStringList() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    vector<string> result;
    string word;
    while (ss >> word) {
        result.push_back(word);
    }
    return result;
}

int main() {
    fastIO;

    // Read the value of k
    int k = readInt();

    // Initialize t to 0
    int t = 0;

    // Loop from 1 to k
    for (int i = 1; i <= k; ++i) {
        // Calculate the value of t using the current value of i and k
        t = ( (t % k) * 10 + 7 ) % k;
        
        // Check if t is a multiple of k
        if (t == 0) {
            // Print the value of i and break out of the loop
            cout << i << endl;
            break;
        }
    }

    // If the loop completes without finding a multiple of k, print -1
    if (t != 0) {
        cout << -1 << endl;
    }

    return 0;
}

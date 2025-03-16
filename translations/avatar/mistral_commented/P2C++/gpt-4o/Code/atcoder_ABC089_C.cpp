#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <numeric>
#include <cmath>
#include <iterator>
#include <tuple>
#include <limits>
#include <iomanip>
#include <functional>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <array>
#include <utility>
#include <bitset>
#include <regex>
#include <climits>
#include <cfloat>

using namespace std;

// Define constants and global variables
const int MOD = 1e9 + 7;  // Modulus value
const int INF = INT_MAX;  // Infinity value
const vector<char> march = {'M', 'A', 'R', 'C', 'H'};  // List of marching orders

// Function to read input as integer
int INT() {
    int x;
    cin >> x;
    return x;
}

// Function to read input as list of integers
vector<int> LIST() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int &x : vec) {
        cin >> x;
    }
    return vec;
}

// Function to read input as list of strings
vector<string> STRING_LIST(int n) {
    vector<string> vec(n);
    for (string &s : vec) {
        cin >> s;
    }
    return vec;
}

int main() {
    // Number of inputs
    int N = INT();
    // List of strings as inputs
    vector<string> S = STRING_LIST(N);
    
    // Initialize march_lis with zeros
    vector<int> march_lis(5, 0);
    
    // Iterate through each string in S and increment the count of the corresponding marching order in march_lis
    for (const string &s : S) {
        char first_char = toupper(s[0]);
        auto it = find(march.begin(), march.end(), first_char);
        if (it != march.end()) {
            march_lis[it - march.begin()]++;
        }
    }
    
    // Calculate the answer by finding the triple product of the counts of each marching order
    long long ans = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            for (int k = j + 1; k < 5; ++k) {
                ans += (long long)march_lis[i] * march_lis[j] * march_lis[k];
            }
        }
    }
    
    // Print the answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>

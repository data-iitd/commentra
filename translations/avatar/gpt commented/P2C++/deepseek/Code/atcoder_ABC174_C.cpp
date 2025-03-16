#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <stack>
#include <climits>
#include <set>
#include <map>

using namespace std;

// Define input functions for convenience
int readInt() {
    int x;
    cin >> x;
    return x;
}

string readString() {
    string s;
    cin >> s;
    return s;
}

vector<int> readInts() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> numbers;
    int num;
    while (ss >> num) {
        numbers.push_back(num);
    }
    return numbers;
}

vector<string> readStrings() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<string> strings;
    string str;
    while (ss >> str) {
        strings.push_back(str);
    }
    return strings;
}

// Set the recursion limit to a higher value to prevent recursion depth errors
const int MAX_RECURSION_LIMIT = 100000;
void setRecursionLimit() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // This is a no-op in C++ and relies on the system's default recursion limit
}

// Define a constant for modulo operations
const int MOD = 1000000007;

int main() {
    setRecursionLimit();
    int k = readInt();
    long long t = 0;

    for (int i = 1; i <= k; ++i) {
        t = (t % k) * 10 + 7;
        if (t % k == 0) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}

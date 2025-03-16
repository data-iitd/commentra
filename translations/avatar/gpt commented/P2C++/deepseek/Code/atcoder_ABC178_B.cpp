#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <cassert>

using namespace std;

#define INF 1e18
#define MOD 1000000007

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;

// Function to read a line of input and return it as a vector of integers
vector<int> read_ints() {
    string line;
    getline(cin, line);
    vector<int> ints;
    string num;
    for (char ch : line) {
        if (ch == ' ') {
            ints.push_back(stoi(num));
            num.clear();
        } else {
            num += ch;
        }
    }
    if (!num.empty()) {
        ints.push_back(stoi(num));
    }
    return ints;
}

// Main function to execute the core logic of the program
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read four integers from input
    vector<int> values = read_ints();
    int a = values[0], b = values[1], c = values[2], d = values[3];
    
    // Calculate the maximum value from the products of the pairs and return it
    int result = max({a * c, b * d, a * d, b * c});
    cout << result << endl;

    return 0;
}

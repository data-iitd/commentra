
#include <bits/stdc++.h>
using namespace std;

// Function to read a single value from input
#define value() tuple<int, int, int>([&](){int a, b, c; cin >> a >> b >> c; return make_tuple(a, b, c); }())

// Function to read multiple values from input
#define values() tuple<int, int, int, int>([&](){int a, b, c, d; cin >> a >> b >> c >> d; return make_tuple(a, b, c, d); }())

// Function to read a list of integers from input
#define inlst() [&](){vector<int> a; int n; cin >> n; while(n--) a.push_back(inp()); return a;}()

// Function to read a list of integers from stdin
#define inlsts() [&](){vector<int> a; int n; cin >> n; while(n--) a.push_back(inps()); return a;}()

// Function to read a single integer from input
#define inp() ([&](){int a; cin >> a; return a;}())

// Function to read a single integer from stdin
#define inps() ([&](){int a; cin >> a; return a;}())

// Function to read a single string from input
#define instr() ([&](){string a; cin >> a; return a;}())

// Function to read a list of strings from input
#define stlst() [&](){vector<string> a; int n; cin >> n; while(n--) a.push_back(instr()); return a;}()

// Helper function to check if a grid of given dimensions can be formed
bool help(int a, int b, vector<int> &l) {
    vector<int> tot;
    for (int i = 0; i < b; i++) {
        tot.push_back(l[i * a]);
    }
    for (int i = 0; i < a; i++) {
        int sum = 0;
        for (int j = 0; j < b; j++) {
            sum += tot[j * a + i];
        }
        if (sum == a) {
            return true;
        }
    }
    return false;
}

// Main solving function
void solve() {
    vector<int> s;
    string x = instr();
    for (char i : x) {
        if (i == 'O') {
            s.push_back(0);
        } else {
            s.push_back(1);
        }
    }
    vector<pair<int, int>> tot;
    for (int i = 1; i <= 12; i++) {
        if (12 % i == 0) {
            if (help(i, 12 / i, s)) {
                tot.push_back(make_pair(12 / i, i));
            }
        }
    }
    cout << tot.size() << " ";
    for (auto [a, b] : tot) {
        cout << a << "x" << b << " ";
    }
    cout << endl;
}

// Main execution block
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


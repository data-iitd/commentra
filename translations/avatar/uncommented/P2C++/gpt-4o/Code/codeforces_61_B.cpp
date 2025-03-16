#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <iterator>
#include <sstream>
#include <cctype>
#include <unordered_set>

using namespace std;

bool valid(int i, int j, int n, int m) {
    return (i < n && i >= 0 && j >= 0 && j < m);
}

long long sumn(int i, int n) {
    return (n - i) * (i + n) / 2;
}

double sqfun(double a, double b, double c) {
    return (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
}

vector<int> value() {
    int x;
    vector<int> res;
    while (cin >> x) {
        res.push_back(x);
        if (cin.peek() == '\n') break;
    }
    return res;
}

vector<int> inlst() {
    int x;
    vector<int> res;
    while (cin >> x) {
        res.push_back(x);
        if (cin.peek() == '\n') break;
    }
    return res;
}

int inp() {
    int x;
    cin >> x;
    return x;
}

string instr() {
    string s;
    cin >> s;
    return s;
}

string f(const string& s) {
    string r;
    for (char i : s) {
        if (i != '-' && i != ';' && i != '_') {
            r += tolower(i);
        }
    }
    return r;
}

void solve() {
    vector<string> l;
    for (int i = 0; i < 3; ++i) {
        string input;
        cin >> input;
        l.push_back(f(input));
    }
    
    set<string> permutations;
    sort(l.begin(), l.end());
    do {
        string perm = l[0] + l[1] + l[2];
        permutations.insert(perm);
    } while (next_permutation(l.begin(), l.end()));
    
    int t = inp();
    for (int i = 0; i < t; ++i) {
        string input;
        cin >> input;
        if (permutations.count(f(input))) {
            cout << "ACC" << endl;
        } else {
            cout << "WA" << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}

// <END-OF-CODE>

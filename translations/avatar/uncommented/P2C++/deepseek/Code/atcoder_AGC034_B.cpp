#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <limits.h>
#include <cassert>

using namespace std;

int gcd(int a, int b) {
    a = max(a, b);
    b = min(a, b);
    while (a % b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return b;
}

void solve() {
    string s;
    cin >> s;
    string t = "";
    int i = 0;
    while (i < s.size()) {
        if (s[i] == 'A') {
            t += "A";
            i++;
        } else if (s[i] == 'B') {
            if (i < s.size() - 1) {
                if (s[i + 1] == 'C') {
                    t += "D";
                    i += 2;
                } else {
                    t += "X";
                    i++;
                }
            } else {
                t += "X";
                i++;
            }
        } else {
            t += "X";
            i++;
        }
    }
    int total = 0;
    int numA = 0;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == 'X') {
            numA = 0;
        } else {
            if (t[i] == 'A') numA++;
            else total += numA;
        }
    }
    cout << total << endl;
}

int main() {
    solve();
    return 0;
}


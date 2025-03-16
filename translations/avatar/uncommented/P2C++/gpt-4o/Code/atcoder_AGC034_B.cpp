#include <iostream>
#include <string>
using namespace std;

long long gcd(long long a, long long b) {
    a = max(a, b);
    b = min(a, b);
    while (a % b > 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return b;
}

void solve() {
    string s;
    cin >> s;
    string t = "";
    int i = 0;
    while (i < s.length()) {
        if (s[i] == 'A') {
            t += 'A';
            i++;
        } else if (s[i] == 'B') {
            if (i < s.length() - 1) {
                if (s[i + 1] == 'C') {
                    t += 'D';
                    i += 2;
                } else {
                    t += 'X';
                    i++;
                }
            } else {
                t += 'X';
                i++;
            }
        } else {
            t += 'X';
            i++;
        }
    }
    
    long long total = 0;
    long long numA = 0;
    for (int i = 0; i < t.length(); i++) {
        if (t[i] == 'X') {
            numA = 0;
        } else {
            if (t[i] == 'A') {
                numA++;
            } else {
                total += numA;
            }
        }
    }
    cout << total << endl;
    const long long INF = 1e25;
    const long long mod = 7 + 1e9;
}

int main() {
    solve();
    return 0;
}

// <END-OF-CODE>

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Main {
private:
    int cal(const string& s, char c) {
        int n = s.length();
        int m = n - 1;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == c && (m & i) == i) {
                ans ^= 1;
            }
        }

        return ans;
    }

    void solve() {
        int n = sc.nextInt();

        for (int testCase = 1; testCase <= n; testCase++) {
            int num = sc.nextInt();
            string s = sc.next();

            stringstream sb;

            for (int i = 1; i < num; i++) {
                sb << abs(s[i] - s[i - 1]);
            }

            if (num == 2) {
                cout << sb.str()[0] << endl;
                continue;
            }

            string s_new = sb.str();

            if (s_new.find('1') != string::npos) {
                cout << cal(s_new, '1') << endl;
            } else {
                cout << cal(s_new, '2') * 2 << endl;
            }
        }
    }

    class MyScanner {
    public:
        int nextInt() {
            int val;
            cin >> val;
            return val;
        }

        string next() {
            string val;
            cin >> val;
            return val;
        }
    };

    MyScanner sc;

public:
    Main() {
        solve();
    }
};

int main() {
    Main mainObj;
    return 0;
}


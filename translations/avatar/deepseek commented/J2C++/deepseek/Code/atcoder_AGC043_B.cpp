#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cctype>
#include <locale>
#include <iomanip>
#include <utility>
#include <numeric>
#include <functional>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Main {
private:
    // This method calculates a result based on a given string and character.
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

    // This method is responsible for solving the problem by processing the input and outputting the result.
    void solve() {
        int n;
        string s;
        cin >> n >> s;
        stringstream sb;
        for (int i = 1; i < n; i++) {
            sb << abs(s[i] - s[i - 1]);
        }
        if (n == 2) {
            cout << sb.str()[0] << endl;
            return;
        }
        s = sb.str();
        if (s.find('1') != string::npos) {
            cout << cal(s, '1') << endl;
        } else {
            cout << cal(s, '2') * 2 << endl;
        }
    }

public:
    // The entry point of the program where objects are created and the solve method is called.
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        solve();
        return 0;
    }
};


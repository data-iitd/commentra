
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

typedef long long ll;
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        vector<pair<int, int>> ans;
        for (int i = 1; i <= 12; i++) {
            if (12 % i == 0) {
                bool ok = true;
                for (int j = 0; j < i; j++) {
                    int sum = 0;
                    for (int k = j; k < n; k += i) {
                        if (s[k] == 'O') sum++;
                    }
                    if (sum!= 12 / i) ok = false;
                }
                if (ok) ans.push_back({12 / i, i});
            }
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << " ";
        for (auto p : ans) {
            cout << p.first << "x" << p.second << " ";
        }
        cout << endl;
    }
    return 0;
}


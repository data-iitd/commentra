
#include <bits/stdc++.h>
using namespace std;

const int initialBufSize = 10000;
const int maxBufSize = 1000000;
const int mod = 1e9 + 7;

int main() {
    vector<string> week = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    string s;
    cin >> s;
    int index = -1;
    for (int i = 0; i < week.size(); i++) {
        if (s == week[i]) {
            index = i;
            break;
        }
    }
    cout << 7 - index << endl;
    return 0;
}


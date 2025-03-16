

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int even0 = 0, even1 = 0, odd0 = 0, odd1 = 0;
    for (int i = 0; i < s.length(); i++) {
        if (i % 2 == 0) {
            if (s[i] == '0') {
                even0++;
            } else {
                even1++;
            }
        } else {
            if (s[i] == '0') {
                odd0++;
            } else {
                odd1++;
            }
        }
    }

    cout << min(even0 + odd1, even1 + odd0) << endl;

    return 0;
}



Translate the above Python code to Java and end with comment "
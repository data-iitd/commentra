
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 0, r = 0;
    bool flag = false;
    bool isTrue = false;
    for (int i = 0; i < n; i++) {
        if (a[i]!= i + 1 &&!flag) {
            l = i + 1;
            flag = true;
            continue;
        }
        if (a[i]!= i + 1 && flag) {
            r = i + 1;
            if (a[r - 1] - a[r - 2] > 0) {
                isTrue = true;
                break;
            }
        }
    }
    cout << (isTrue? "0 0" : to_string(l) + " " + to_string(r)) << endl;
    return 0;
}




#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (a[0] == 1) {
        cout << -1 << endl;
    } else {
        cout << a[0] << endl;
    }
    return 0;
}
// This C++ code reads the input, sorts the list of integers, and prints the first element if it is not equal to 1, otherwise it prints -1.

Translate the above Python code to Java and end with comment "
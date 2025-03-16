#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> a;
    for (int i = 0; i < s.size(); i++) {
        a.push_back(s[i] - '0');
    }
    sort(a.begin(), a.end());
    for (int i = 1; i < a.size(); i++) {
        if (a[i] != a[i - 1] && a[i] < a[i - 1] * 2) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}


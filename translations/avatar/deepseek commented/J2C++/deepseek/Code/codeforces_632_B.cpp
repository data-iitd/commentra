#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    string s;
    cin >> s;

    long long sum = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'B') {
            sum += a[i];
        }
    }

    long long ans = sum;
    long long sum1 = sum;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') {
            sum1 += a[i];
        } else {
            sum1 -= a[i];
        }
        ans = max(ans, sum1);
    }

    sum1 = sum;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == 'A') {
            sum1 += a[i];
        } else {
            sum1 -= a[i];
        }
        ans = max(ans, sum1);
    }

    cout << ans << endl;


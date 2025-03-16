#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<long long> v;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        v.push_back(x);
    }
    long long sum = 0;
    for (long long i : v) {
        if (i % 2 == 0) {
            sum += i;
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        if (i % 2!= 0) {
            sum += v[i];
        }
    }
    if (v.size() % 2!= 0) {
        sum -= v[0];
    }
    cout << sum << endl;
    return 0;
}

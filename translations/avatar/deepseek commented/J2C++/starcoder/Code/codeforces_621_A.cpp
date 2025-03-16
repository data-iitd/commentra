
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
    vector<long long> odd;
    for (long long i : v) {
        if (i % 2 == 0) {
            sum += i;
        } else {
            odd.push_back(i);
        }
    }
    sort(odd.begin(), odd.end());
    for (long long i : odd) {
        sum += i;
    }
    if (odd.size() % 2!= 0) {
        sum -= odd[0];
    }
    cout << sum << endl;
    return 0;
}


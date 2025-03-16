#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long k;
    cin >> n >> k;

    long arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int count = 0;
    set<long> s;
    for (int i = 0; i < n; i++) {
        if (arr[i] % k!= 0) {
            count++;
            s.insert(arr[i]);
        } else if (s.find(arr[i] / k) == s.end()) {
            count++;
            s.insert(arr[i]);
        }
    }

    cout << count << "\n";
}


#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int total = 0;
    for (int i = 0; i < N; i++) {
        total ^= a[i];
    }

    for (int i = 0; i < N; i++) {
        cout << a[i] ^ total << " ";
    }
    cout << endl;

    return 0;
}


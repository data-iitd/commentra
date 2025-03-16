#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int ReadInt() {
    int v;
    cin >> v;
    return v;
}

vector<int> ReadInts(int n) {
    vector<int> ret(n);
    for (int i = 0; i < n; i++) {
        ret[i] = ReadInt();
    }
    return ret;
}

int main() {
    int N = ReadInt();
    int K = ReadInt();
    vector<int> As = ReadInts(N);
    vector<int> Fs = ReadInts(N);

    sort(As.begin(), As.end());
    sort(Fs.begin(), Fs.end(), greater<int>());

    long long ok = 1e18;
    long long ng = -1;

    while (ok - ng > 1) {
        long long mid = (ok + ng) / 2;

        bool isOK = true;
        long long k = K;
        for (int i = 0; isOK && i < N; i++) {
            if (As[i] * Fs[i] > mid) {
                k -= As[i] - mid / Fs[i];
            }
            if (k < 0) {
                isOK = false;
            }
        }

        if (isOK) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    cout << ok << endl;
    return 0;
}

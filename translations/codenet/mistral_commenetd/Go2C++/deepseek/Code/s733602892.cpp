#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

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

bool isOK(int mid, int K, vector<int>& As, vector<int>& Fs) {
    long long k = K;
    for (int i = 0; i < As.size(); i++) {
        if (As[i] * Fs[i] > mid) {
            k -= As[i] - mid / Fs[i];
        }
        if (k < 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int N = ReadInt();
    int K = ReadInt();

    vector<int> As = ReadInts(N);
    vector<int> Fs = ReadInts(N);

    sort(As.begin(), As.end());
    sort(Fs.begin(), Fs.end(), greater<int>());

    int ok = As[N - 1] * Fs[0];
    int ng = -1;

    while (ok - ng > 1) {
        int mid = (ok + ng) / 2;
        if (isOK(mid, K, As, Fs)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    cout << ok << endl;

    return 0;
}

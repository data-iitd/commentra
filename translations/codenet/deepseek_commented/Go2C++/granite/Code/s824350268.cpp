

#include <bits/stdc++.h>
using namespace std;

const int initialBufSize = 10000;
const int maxBufSize = 1000000;
const int mod = 1e9 + 7;

int N, sqrtN, min;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    sqrtN = sqrt(N);
    min = N;

    for (int i = 1; i <= sqrtN; i++) {
        if (N % i!= 0) {
            continue;
        }

        int num = i + (N / i) - 2;
        if (num < min) {
            min = num;
        }
    }

    cout << min << endl;

    return 0;
}



#include <iostream>
#include <map>

using namespace std;

int Abs(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

int min(int a, int b) {
    if (a > b) {
        return b;
    }
    return a;
}

int main() {
    int N, K;
    cin >> N >> K;

    // map<int, bool> hm;
    // while (true) {
    //     if (!hm[N]) {
    //         hm[N] = true;
    //         N = Abs(N - K);
    //     } else {
    //         break;
    //     }
    // }

    // int mini = 999999999;
    // for (auto k : hm) {
    //     mini = min(mini, k.first);
    // }
    // cout << mini << endl;

    int x = N % K;
    x = min(Abs(x - K), x);
    cout << x << endl;

    return 0;
}


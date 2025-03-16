#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    string S;
    cin >> N >> K >> S;

    int seg_cnt = 0;
    for (int i = 0; i < N - 1; i++) {
        if (S[i] != S[i + 1]) {
            seg_cnt++;
        }
    }

    int cur_happy = N - 1 - seg_cnt;

    if (2 * K >= seg_cnt) {
        cout << N - 1 << endl;
    } else {
        cout << cur_happy + 2 * K << endl;
    }

    return 0;
}


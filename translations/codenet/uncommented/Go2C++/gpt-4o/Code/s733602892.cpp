#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> As(N), Fs(N);
    for (int i = 0; i < N; i++) {
        cin >> As[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> Fs[i];
    }

    sort(As.begin(), As.end());
    sort(Fs.rbegin(), Fs.rend());
    
    vector<int> scores(N);
    for (int i = 0; i < N; i++) {
        scores[i] = As[i] * Fs[i];
    }
    sort(scores.rbegin(), scores.rend());

    int ok = scores[0];
    int ng = -1;
    while (ok - ng > 1) {
        int mid = (ok + ng) / 2;

        bool isOK = true;
        int k = K;
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

// <END-OF-CODE>

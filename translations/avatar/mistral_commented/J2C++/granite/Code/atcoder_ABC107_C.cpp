

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K; // Read the number of elements and the size of the sliding window from the standard input

    int S[N]; // Allocate an integer array of size N to store the input elements

    for (int i = 0; i < N; i++) {
        cin >> S[i]; // Read the next integer and store it in the array
    }

    int temp = 0;
    int ans = 1000000000;

    if (K == 1) {
        for (int i = 0; i < N; i++) {
            temp = S[i];
            ans = min(abs(temp), ans);
        }
        cout << ans << endl;
    } else if (N - K!= 0) {
        int min, max;
        for (int i = 0; i <= N - K; i++) {
            min = S[i];
            max = S[i + K - 1];
            if (min < 0 && max > 0) {
                temp = 2 * (abs(min)) + max;
            } else {
                temp = max(abs(min), abs(max));
            }
            ans = min(ans, temp);
        }
        cout << ans << endl;
    } else {
        int min = S[0];
        int max = S[N - 1];
        if (min < 0 && max > 0) {
            cout << min(2 * (abs(min)) + max, (abs(min)) + 2 * max) << endl;
        } else {
            cout << max(abs(min), abs(max)) << endl;
        }
    }

    return 0;
}


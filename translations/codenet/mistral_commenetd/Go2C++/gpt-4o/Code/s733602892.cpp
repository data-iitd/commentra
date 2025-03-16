#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    // Read input: N and K
    int N, K;
    cin >> N >> K;

    // Read input: N integers As
    vector<int> As(N);
    for (int i = 0; i < N; i++) {
        cin >> As[i];
    }

    // Read input: N integers Fs
    vector<int> Fs(N);
    for (int i = 0; i < N; i++) {
        cin >> Fs[i];
    }

    // Sort As in ascending order and Fs in descending order
    sort(As.begin(), As.end());
    sort(Fs.rbegin(), Fs.rend());

    // Calculate the score for each element in As
    vector<int> scores(N);
    for (int i = 0; i < N; i++) {
        scores[i] = As[i] * Fs[i];
    }

    // Sort scores in descending order
    sort(scores.rbegin(), scores.rend());

    // Binary search to find the answer
    int ok = scores[0];
    int ng = -1;
    while (ok - ng > 1) {
        int mid = (ok + ng) / 2;

        // Check if it's possible to distribute the flowers to K students with the given mid score
        bool isOK = true;
        int k = K;
        for (int i = 0; isOK && i < N; i++) {
            if (As[i] * Fs[i] > mid) {
                // Subtract the difference between mid and the product of the current element from the remaining flowers
                k -= As[i] - mid / Fs[i];
            }
            if (k < 0) {
                // If the remaining flowers are not enough to distribute to all students, it's not possible to distribute the flowers with the given mid score
                isOK = false;
                break;
            }
        }

        if (isOK) {
            // If it's possible to distribute the flowers with the given mid score, update ok with mid
            ok = mid;
        } else {
            // If it's not possible to distribute the flowers with the given mid score, update ng with mid
            ng = mid;
        }
    }

    // Print the answer
    cout << ok << endl;

    return 0;
}

// <END-OF-CODE>

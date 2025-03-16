#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    // Read the number of elements N and the threshold K
    int N, K;
    cin >> N >> K;

    // Read the two vectors of integers As and Fs
    vector<int> As(N), Fs(N);
    for (int i = 0; i < N; i++) {
        cin >> As[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> Fs[i];
    }

    // Sort the As vector in ascending order
    sort(As.begin(), As.end());
    // Sort the Fs vector in descending order
    sort(Fs.rbegin(), Fs.rend());

    // Create a vector to hold the scores calculated from As and Fs
    vector<int> scores(N);
    for (int i = 0; i < N; i++) {
        // Calculate the score for each pair of As and Fs
        scores[i] = As[i] * Fs[i];
    }

    // Sort the scores in descending order
    sort(scores.rbegin(), scores.rend());

    // Initialize binary search boundaries
    int ok = scores[0]; // The maximum possible score
    int ng = -1;        // The minimum possible score

    // Perform binary search to find the maximum score that can be achieved
    while (ok - ng > 1) {
        int mid = (ok + ng) / 2; // Calculate the midpoint of the current range

        bool isOK = true; // Flag to check if the current mid is achievable
        int k = K;        // Remaining threshold to adjust scores
        for (int i = 0; isOK && i < N; i++) {
            // If the current score exceeds mid, calculate how much we need to reduce
            if (As[i] * Fs[i] > mid) {
                k -= As[i] - mid / Fs[i];
            }
            // If we exceed the allowed threshold, mark isOK as false
            if (k < 0) {
                isOK = false;
            }
        }

        // Adjust binary search boundaries based on whether mid is achievable
        if (isOK) {
            ok = mid; // If achievable, move the upper boundary
        } else {
            ng = mid; // If not achievable, move the lower boundary
        }
    }

    // Print the maximum achievable score
    cout << ok << endl;

    return 0;
}

// <END-OF-CODE>

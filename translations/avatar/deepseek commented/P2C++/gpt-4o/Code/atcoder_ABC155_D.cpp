#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long N, K;
    cin >> N >> K; // Reading N and K
    vector<long long> A(N);
    for (long long i = 0; i < N; i++) {
        cin >> A[i]; // Reading list A
    }
    sort(A.begin(), A.end()); // Sorting the list A

    // Binary search setup
    long long ll = -1e18 - 1; // Lower limit initialized to a very small number
    long long rr = 1e18 + 1; // Upper limit initialized to a very large number

    // Binary search execution
    while (ll + 1 < rr) {
        long long x = (ll + rr) / 2; // Calculating the midpoint of the current range
        long long tot = 0; // Initializing the total count of valid pairs

        // Counting valid pairs for each element in A
        for (long long i = 0; i < N; i++) {
            if (A[i] < 0) {
                long long l = -1;
                long long r = N;
                while (l + 1 < r) {
                    long long c = (l + r) / 2;
                    if (A[i] * A[c] < x) {
                        r = c;
                    } else {
                        l = c;
                    }
                }
                tot += N - r; // Updating the total count for negative A[i]
            } else {
                long long l = -1;
                long long r = N;
                while (l + 1 < r) {
                    long long c = (l + r) / 2;
                    if (A[i] * A[c] < x) {
                        l = c;
                    } else {
                        r = c;
                    }
                }
                tot += r; // Updating the total count for non-negative A[i]
            }

            if (A[i] * A[i] < x) {
                tot -= 1; // Adjusting for the pair (i, i) if necessary
            }
        }

        tot /= 2; // Dividing by 2 to correct for double-counting pairs

        // Adjusting the search range based on the total count
        if (tot < K) {
            ll = x;
        } else {
            rr = x;
        }
    }

    cout << ll << endl; // Output the result
    return 0;
} // <END-OF-CODE>

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long N, K;
    cin >> N >> K;
    vector<long long> A(N);
    for (long long i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    long long ll = -1e18 - 1;
    long long rr = 1e18 + 1;
    
    while (ll + 1 < rr) {
        long long x = (ll + rr) / 2;
        long long tot = 0;
        
        for (long long i = 0; i < N; i++) {
            if (A[i] < 0) {
                long long l = -1, r = N;
                while (l + 1 < r) {
                    long long c = (l + r) / 2;
                    if (A[i] * A[c] < x) {
                        r = c;
                    } else {
                        l = c;
                    }
                }
                tot += N - r;
            } else {
                long long l = -1, r = N;
                while (l + 1 < r) {
                    long long c = (l + r) / 2;
                    if (A[i] * A[c] < x) {
                        l = c;
                    } else {
                        r = c;
                    }
                }
                tot += r;
            }
            if (A[i] * A[i] < x) {
                tot -= 1;
            }
        }
        tot /= 2;
        
        if (tot < K) {
            ll = x;
        } else {
            rr = x;
        }
    }
    
    cout << ll << endl;
    return 0;
}

// <END-OF-CODE>

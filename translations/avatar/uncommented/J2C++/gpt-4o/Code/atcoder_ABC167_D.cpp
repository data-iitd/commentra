#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Main {
public:
    void doIt() {
        const int MOD = 1000000007;
        const int MAX = INT_MAX;
        const long LMAX = LONG_MAX;
        int len = 1e6 + 1;

        int N;
        long K;
        cin >> N >> K;

        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
            A[i]--; // Adjusting to 0-based index
        }

        unordered_set<int> used;
        vector<int> idx(N);
        vector<int> pos(N);
        int next = 0, cur = 0;

        while (used.find(next) == used.end()) {
            used.insert(next);
            idx[next] = cur;
            pos[cur] = next;
            next = A[next];
            cur++;
        }

        long a = (long)cur - idx[next];
        long b = (long)idx[next];
        int ans = (int)((10000 * a + K - b) % a + b);
        if (b > K) ans = (int)K;

        cout << pos[ans] + 1 << endl; // Adjusting back to 1-based index
    }
};

int main() {
    Main().doIt();
    return 0;
}

// <END-OF-CODE>

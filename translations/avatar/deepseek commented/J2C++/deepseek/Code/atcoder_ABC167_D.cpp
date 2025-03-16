#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

const int MOD = 1000000007;
const long long LMAX = LLONG_MAX;
const int MAX = INT_MAX;

class Main {
private:
    int len = 1e6 + 1;

public:
    void doIt() {
        int N;
        long long K;
        cin >> N >> K;

        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            --A[i]; // Adjust for 0-based indexing
        }

        unordered_set<int> used;
        vector<int> idx(N);
        vector<int> pos(N);

        int next = 0, cur = 0;

        // Detect the cycle in the array A
        while (used.find(next) == used.end()) {
            used.insert(next);
            idx[next] = cur;
            pos[cur] = next;
            next = A[next];
            ++cur;
        }

        // Calculate the length of the cycle and adjust the position based on K
        long long a = cur - idx[next];
        long long b = idx[next];
        int ans = (int)((10000 * a + K - b) % a + b);

        // Adjust the answer if necessary based on the cycle length
        if (b > K) ans = (int)K;

        // Output the final position
        cout << pos[ans] + 1 << endl;
    }
};

int main() {
    Main().doIt();
    return 0;
}


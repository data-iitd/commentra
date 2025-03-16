#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

const int MOD = 1000000007;
const long long LMAX = LLONG_MAX;
const int MAX = INT_MAX;

class Main {
public:
    void doIt() {
        int N;
        long long K;
        cin >> N >> K;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
            A[i]--;
        }
        vector<int> idx(N);
        vector<int> pos(N);
        set<int> used;
        int next = 0, cur = 0;
        while (used.find(next) == used.end()) {
            used.insert(next);
            idx[next] = cur;
            pos[cur] = next;
            next = A[next];
            cur++;
        }
        long long a = cur - idx[next];
        long long b = idx[next];
        int ans = (int)((10000 * a + K - b) % a + b);
        if (b > K) ans = (int)K;
        cout << pos[ans] + 1 << endl;
    }
};

int main() {
    Main().doIt();
    return 0;
}


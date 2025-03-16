#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Main {
public:
    const int MOD = 1000000007;
    const int MAX = INT_MAX;
    const long long LMAX = LLONG_MAX;
    int len = 1e6 + 1;

    void doIt() {
        int N;
        long long K;
        cin >> N >> K;
        vector<int> A(N);

        for (int i = 0; i < N; i++) {
            cin >> A[i];
            A[i]--;
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

        long long a = cur - idx[next];
        long long b = idx[next];
        int ans = (10000 * a + K - b + MOD) % a + b;

        if (b > K) {
            ans = (int) K;
        }

        cout << pos[ans] + 1 << endl;
    }
};

int main() {
    Main obj;
    obj.doIt();
    return 0;
}


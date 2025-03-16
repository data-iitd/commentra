#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int N, K, d, a;
    cin >> N >> K;
    unordered_map<int, int> as;

    for (int i = 1; i <= N; i++) {
        as[i] = 0;
    }

    for (int i = 0; i < K; i++) {
        cin >> d;
        for (int j = 0; j < d; j++) {
            cin >> a;
            as[a]++;
        }
    }

    int ans = 0;
    for (const auto& pair : as) {
        if (pair.second == 0) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    string S;
    cin >> N >> K >> S;

    bool aaaa = false;
    if (K >= 15 || (1 << K) >= N) {
        aaaa = true;
    }

    if (aaaa) {
        char minChar = *min_element(S.begin(), S.end());
        string ans = string(N, minChar);
        cout << ans << endl;
        return 0;
    }

    string U = S + string(S.rbegin(), S.rend());
    char minChar = *min_element(S.begin(), S.end());
    int minIndex = U.find(minChar);
    int p = minIndex + 1;
    while (p <= N) {
        if (U[p] == minChar) {
            if (check_normal(U, minIndex, p)) {
                minIndex = p;
            }
        }
        p++;
    }
    string ans = U.substr(minIndex, N);
    cout << ans << endl;

    return 0;
}

bool check_normal(string U, int pointer1, int pointer2) {
    for (int i = 0; i < N; i++) {
        if (U[pointer1 + i] > U[pointer2 + i]) {
            return true;
        } else if (U[pointer1 + i] < U[pointer2 + i]) {
            return false;
        }
    }
    return false;
}

// 
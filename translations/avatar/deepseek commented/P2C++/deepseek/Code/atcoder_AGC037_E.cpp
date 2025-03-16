#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    bool aaaa = false;
    if (K >= 15) {
        aaaa = true;
    } else if (pow(2, K) >= N) {
        aaaa = true;
    }
    if (aaaa) {
        char minChar = *min_element(S.begin(), S.end());
        cout << minChar * N << endl;
        return 0;
    }

    auto get_last_dict = [](const string& s_str) {
        string U = s_str + s_str;
        char c = *min_element(s_str.begin(), s_str.end());
        int p = U.find(c);
        int minindex = p;
        p += 1;
        while (p <= s_str.size()) {
            if (U[p] == c) {
                if (check_normal_dict(U, minindex, p, s_str.size())) {
                    minindex = p;
                }
            }
            p += 1;
        }
        return U.substr(minindex, s_str.size());
    };

    auto check_normal_dict = [](const string& u, int pointer1, int pointer2, int N) {
        for (int i = 0; i < N; ++i) {
            if (u[pointer1 + i] > u[pointer2 + i]) {
                return true;
            } else if (u[pointer1 + i] < u[pointer2 + i]) {
                return false;
            }
        }
        return false;
    };

    S = get_last_dict(S);

    if (K == 1) {
        cout << S << endl;
    } else {
        int count = 0;
        for (char c : S) {
            if (c == S[0]) {
                count += 1;
            } else {
                break;
            }
        }
        if (count * (pow(2, K - 1)) >= N) {
            cout << string(N, S[0]) << endl;
        } else {
            string new_S = string(count * (pow(2, K - 1) - 1), S[0]) + S;
            cout << new_S.substr(0, N) << endl;
        }
    }

    return 0;
}


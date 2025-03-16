#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N, K;

string get_last_dict(const string& s_str) {
    string U = s_str + string(s_str.rbegin(), s_str.rend());
    char c = *min_element(s_str.begin(), s_str.end());
    size_t p = U.find(c);
    size_t minindex = p;
    p += 1;

    while (p <= N) {
        if (U[p] == c) {
            if (check_normal_dict(U, minindex, p)) {
                minindex = p;
            }
        }
        p++;
    }
    return U.substr(minindex, N);
}

bool check_normal_dict(const string& u, size_t pointer1, size_t pointer2) {
    for (int i = 0; i < N; i++) {
        if (u[pointer1 + i] > u[pointer2 + i]) {
            return true;
        } else if (u[pointer1 + i] < u[pointer2 + i]) {
            return false;
        }
    }
    return false;
}

int main() {
    cin >> N >> K;
    string S;
    cin >> S;

    bool aaaa = false;
    if (K >= 15) {
        aaaa = true;
    } else if ((1 << K) >= N) {
        aaaa = true;
    }

    if (aaaa) {
        cout << string(N, *min_element(S.begin(), S.end())) << endl;
        return 0;
    }

    S = get_last_dict(S);
    if (K == 1) {
        cout << S << endl;
    } else {
        int count = 0;
        for (char c : S) {
            if (c == S[0]) {
                count++;
            } else {
                break;
            }
        }
        if (count * (1 << (K - 1)) >= N) {
            cout << string(N, S[0]) << endl;
        } else {
            S = string(count * ((1 << (K - 1)) - 1), S[0]) + S;
            cout << S.substr(0, N) << endl;
        }
    }

    return 0;
}

// <END-OF-CODE>

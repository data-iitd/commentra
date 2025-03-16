#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int N, K, R, S, P;
    string T;
    cin >> N >> K >> R >> S >> P;
    cin >> T;

    unordered_map<char, int> dict = {{'r', 0}, {'s', 0}, {'p', 0}};
    vector<bool> s(N, true);
    vector<bool> r(N, true);
    vector<bool> p(N, true);

    for (int i = 0; i < N; i++) {
        char char_ = T[i];
        if (i >= K) {
            if (char_ == T[i - K]) {
                switch (char_) {
                    case 's':
                        if (s[i % K]) {
                            s[i % K] = false;
                            continue;
                        } else {
                            s[i % K] = true;
                        }
                    case 'r':
                        if (r[i % K]) {
                            r[i % K] = false;
                            continue;
                        } else {
                            r[i % K] = true;
                        }
                    case 'p':
                        if (p[i % K]) {
                            p[i % K] = false;
                            continue;
                        } else {
                            p[i % K] = true;
                        }
                }
            } else {
                switch (char_) {
                    case 's':
                        s[i % K] = true;
                        break;
                    case 'r':
                        r[i % K] = true;
                        break;
                    case 'p':
                        p[i % K] = true;
                        break;
                }
            }
        }
        dict[char_]++;
    }

    int res = P * dict['r'] + S * dict['p'] + R * dict['s'];
    cout << res << endl;

    return 0;
}

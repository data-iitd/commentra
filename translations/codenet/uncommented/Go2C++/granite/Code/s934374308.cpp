
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int N, K, R, S, P;
    string T;
    cin >> N >> K >> R >> S >> P;
    cin >> T;

    map<char, int> dict;
    dict['r'] = 0;
    dict['s'] = 0;
    dict['p'] = 0;

    char char;
    bool s[N];
    bool r[N];
    bool p[N];
    for (int i = 0; i < N; i++) {
        s[i] = true;
        r[i] = true;
        p[i] = true;
    }
    for (int i = 0; i < T.length(); i++) {
        char = T[i];
        if (i >= K) {
            if (char == T[i-K]) {
                switch (char) {
                    case's':
                        if (s[i%K]) {
                            s[i%K] = false;
                            continue;
                        } else {
                            s[i%K] = true;
                        }
                        break;
                    case 'r':
                        if (r[i%K]) {
                            r[i%K] = false;
                            continue;
                        } else {
                            r[i%K] = true;
                        }
                        break;
                    case 'p':
                        if (p[i%K]) {
                            p[i%K] = false;
                            continue;
                        } else {
                            p[i%K] = true;
                        }
                        break;
                }
            } else {
                switch (char) {
                    case's':
                        s[i%K] = true;
                        break;
                    case 'r':
                        r[i%K] = true;
                        break;
                    case 'p':
                        p[i%K] = true;
                        break;
                }
            }
        }
        switch (char) {
            case's':
                dict['s'] = dict['s'] + 1;
                break;
            case 'r':
                dict['r'] = dict['r'] + 1;
                break;
            case 'p':
                dict['p'] = dict['p'] + 1;
                break;
        }
    }

    int res = P*dict['r'] + S*dict['p'] + R*dict['s'];
    cout << res << endl;

    return 0;
}

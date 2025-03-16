
#include <iostream>
#include <string>
#include <map>

int main() {
    int N, K, R, S, P;
    std::string T;
    std::cin >> N >> K >> R >> S >> P;
    std::cin >> T;

    std::map<char, int> dict = { {'r', 0}, {'s', 0}, {'p', 0} };
    char current_char = '\0';
    bool s[N], r[N], p[N];
    for (int i = 0; i < N; i++) {
        s[i] = true;
        r[i] = true;
        p[i] = true;
    }

    for (int i = 0; i < T.length(); i++) {
        current_char = T[i];
        if (i >= K) {
            if (current_char == T[i-K]) {
                switch (current_char) {
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
                switch (current_char) {
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
        dict[current_char]++;
    }

    int result = P*dict['r'] + S*dict['p'] + R*dict['s'];
    std::cout << result << std::endl;

    return 0;
}

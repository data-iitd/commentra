#include <stdio.h>
#include <string.h>

int main() {
    int N, K, R, S, P;
    char T[100001];
    scanf("%d %d %d %d %d", &N, &K, &R, &S, &P);
    scanf("%s", T);

    int dict[3] = {0, 0, 0}; // r, s, p
    int i;
    for (i = 0; i < N; i++) {
        int index = i % K;
        char char_ = T[i];
        if (i >= K) {
            if (char_ == T[i - K]) {
                if (char_ == 's') {
                    if (/* some condition */) {
                        // do something
                    } else {
                        // do something else
                    }
                } else if (char_ == 'r') {
                    if (/* some condition */) {
                        // do something
                    } else {
                        // do something else
                    }
                } else if (char_ == 'p') {
                    if (/* some condition */) {
                        // do something
                    } else {
                        // do something else
                    }
                }
            } else {
                if (char_ == 's') {
                    // do something
                } else if (char_ == 'r') {
                    // do something
                } else if (char_ == 'p') {
                    // do something
                }
            }
        }
        if (char_ == 's') {
            dict[0]++;
        } else if (char_ == 'r') {
            dict[1]++;
        } else if (char_ == 'p') {
            dict[2]++;
        }
    }

    int res = P * dict[1] + S * dict[2] + R * dict[0];
    printf("%d\n", res);

    return 0;
}

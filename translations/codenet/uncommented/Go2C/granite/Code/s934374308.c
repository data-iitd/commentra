
#include <stdio.h>

int main() {
    int N, K, R, S, P;
    char T[100001];
    scanf("%d %d %d %d %d", &N, &K, &R, &S, &P);
    scanf("%s", T);

    int dict[3] = {0};
    char char;
    int s[100001] = {0};
    int r[100001] = {0};
    int p[100001] = {0};
    for (int i = 0; i < N; i++) {
        s[i] = 1;
        r[i] = 1;
        p[i] = 1;
    }
    for (int i = 0; i < strlen(T); i++) {
        char = T[i];
        if (i >= K) {
            if (char == T[i-K]) {
                switch (char) {
                    case's':
                        if (s[(i)%K] == 1) {
                            s[(i)%K] = 0;
                            continue;
                        } else {
                            s[(i)%K] = 1;
                        }
                        break;
                    case 'r':
                        if (r[(i)%K] == 1) {
                            r[(i)%K] = 0;
                            continue;
                        } else {
                            r[(i)%K] = 1;
                        }
                        break;
                    case 'p':
                        if (p[(i)%K] == 1) {
                            p[(i)%K] = 0;
                            continue;
                        } else {
                            p[(i)%K] = 1;
                        }
                        break;
                }
            } else {
                switch (char) {
                    case's':
                        s[(i)%K] = 1;
                        break;
                    case 'r':
                        r[(i)%K] = 1;
                        break;
                    case 'p':
                        p[(i)%K] = 1;
                        break;
                }
            }
        }
        switch (char) {
            case's':
                dict[0] = dict[0] + 1;
                break;
            case 'r':
                dict[1] = dict[1] + 1;
                break;
            case 'p':
                dict[2] = dict[2] + 1;
                break;
        }
    }

    int res = P*dict[0] + S*dict[1] + R*dict[2];
    printf("%d\n", res);

    return 0;
}

#include <stdio.h>
#include <string.h>

int main() {
    int N, K, R, S, P;
    char T[100001]; // Assuming maximum length of T is 100000
    scanf("%d %d %d %d %d", &N, &K, &R, &S, &P);
    scanf("%s", T);

    int dict[3] = {0, 0, 0}; // dict[0] for 'r', dict[1] for 's', dict[2] for 'p'
    char char_current;
    int s[100000] = {1}; // Initialize all to true (1)
    int r[100000] = {1}; // Initialize all to true (1)
    int p[100000] = {1}; // Initialize all to true (1)

    for (int i = 0; i < N; i++) {
        char_current = T[i];
        if (i >= K) {
            if (char_current == T[i - K]) {
                switch (char_current) {
                    case 's':
                        if (s[i % K]) {
                            s[i % K] = 0; // Set to false (0)
                            continue;
                        } else {
                            s[i % K] = 1; // Set to true (1)
                        }
                        break;

                    case 'r':
                        if (r[i % K]) {
                            r[i % K] = 0; // Set to false (0)
                            continue;
                        } else {
                            r[i % K] = 1; // Set to true (1)
                        }
                        break;

                    case 'p':
                        if (p[i % K]) {
                            p[i % K] = 0; // Set to false (0)
                            continue;
                        } else {
                            p[i % K] = 1; // Set to true (1)
                        }
                        break;
                }
            } else {
                switch (char_current) {
                    case 's':
                        s[i % K] = 1; // Set to true (1)
                        break;
                    case 'r':
                        r[i % K] = 1; // Set to true (1)
                        break;
                    case 'p':
                        p[i % K] = 1; // Set to true (1)
                        break;
                }
            }
        }
        switch (char_current) {
            case 's':
                dict[1]++; // Increment count for 's'
                break;
            case 'r':
                dict[0]++; // Increment count for 'r'
                break;
            case 'p':
                dict[2]++; // Increment count for 'p'
                break;
        }
    }

    int res = P * dict[0] + S * dict[2] + R * dict[1];
    printf("%d\n", res);

    return 0;
}

// <END-OF-CODE>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>

#define INF INT_MAX
#define MOD 1000000007

int input() {
    char line[100];
    fgets(line, sizeof(line), stdin);
    return atoi(line);
}

int main() {
    int N = input();
    char S[N][10];
    char march[5] = {'M', 'A', 'R', 'C', 'H'};
    int march_lis[5] = {0};

    for (int i = 0; i < N; i++) {
        scanf("%s", S[i]);
        for (int j = 0; S[i][j]; j++) {
            for (int k = 0; k < 5; k++) {
                if (toupper(S[i][j]) == march[k]) {
                    march_lis[k]++;
                    break;
                }
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            for (int k = j + 1; k < 5; k++) {
                ans += (long long)march_lis[i] * march_lis[j] * march_lis[k];
            }
        }
    }

    printf("%lld\n", ans);
    return 0;
}


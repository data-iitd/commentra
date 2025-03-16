#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>

#define INT() (int)strtol(readline().c_str(), NULL, 10)
#define LIST() (fgetcsv(stdin))
#define ZIP(n) (fgetcsv(stdin, n))
#define INF INT_MAX
#define MOD 1000000007

int main() {
    int N;
    char **S;
    char *march[] = {"M", "A", "R", "C", "H"};
    int march_lis[5] = {0};
    int ans = 0;

    scanf("%d", &N);
    S = (char **)malloc(N * sizeof(char *));
    for (int i = 0; i < N; i++) {
        S[i] = (char *)malloc(10 * sizeof(char));
        scanf("%s", S[i]);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            if (strncasecmp(S[i], march[j], 1) == 0) {
                march_lis[j]++;
                break;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            for (int k = j + 1; k < 5; k++) {
                ans += march_lis[i] * march_lis[j] * march_lis[k];
            }
        }
    }

    printf("%d\n", ans);

    for (int i = 0; i < N; i++) {
        free(S[i]);
    }
    free(S);

    return 0;
}

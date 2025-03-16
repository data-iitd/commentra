#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    
    char S[1000001]; // Assuming maximum length of S is 1,000,000
    scanf("%s", S);

    if (N < 4) {
        printf("0\n");
        return 0;
    }

    int nr = 0, nb = 0, ng = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'R') {
            nr++;
        } else if (S[i] == 'B') {
            nb++;
        } else if (S[i] == 'G') {
            ng++;
        }
    }

    int same = 0;
    for (int a = 1; a < N; a++) {
        int i = 0;
        int j = 1 * a;
        int k = 2 * a;
        if (k >= N) {
            break;
        }
        while (k < N) {
            if (S[i] != S[j] && S[i] != S[k] && S[j] != S[k]) {
                same++;
            }
            i++;
            j++;
            k++;
        }
    }

    int tot = nr * nb * ng;
    printf("%d\n", tot - same);

    return 0;
}

// <END-OF-CODE>

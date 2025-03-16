
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N;
    scanf("%d", &N);
    int S[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &S[i]);
    }
    int flag[N];
    for (int i = 0; i < N; i++) {
        flag[i] = 1;
    }
    int cur[N];
    cur[0] = S[0];
    flag[0] = 0;
    int j = 0;
    int jM = N;
    for (int i = 1; i < N; i++) {
        for (int k = 0; k < N; k++) {
            if (flag[k] && S[k] < cur[j]) {
                cur[j + 1] = S[k];
                j++;
                flag[k] = 0;
                if (j == jM) {
                    goto END;
                }
            }
        }
        return 0;
    END:
        for (int k = 0; k < N; k++) {
            flag[k] = 1;
        }
        j = 0;
        jM = N;
    }
    printf("Yes\n");
    return 0;
}
// END-OF-CODE
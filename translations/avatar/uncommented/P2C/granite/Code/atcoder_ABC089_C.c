
#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    char S[N][10];
    int march[5] = {0};
    for (int i = 0; i < N; i++) {
        scanf("%s", S[i]);
        if (S[i][0] == 'M') {
            march[0]++;
        } else if (S[i][0] == 'A') {
            march[1]++;
        } else if (S[i][0] == 'R') {
            march[2]++;
        } else if (S[i][0] == 'C') {
            march[3]++;
        } else if (S[i][0] == 'H') {
            march[4]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            for (int k = j + 1; k < 5; k++) {
                ans += march[i] * march[j] * march[k];
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
//END-OF-CODE
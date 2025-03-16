#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    int N;
    char S[100001];
    scanf("%d", &N);
    scanf("%s", S);

    int rNum = 0, gNum = 0, bNum = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'R') rNum++;
        else if (S[i] == 'G') gNum++;
        else if (S[i] == 'B') bNum++;
    }

    int sum = 0;
    for (int step = 1; step <= (N + 1) / 2; step++) {
        for (int i = 0; i <= N - 2 * step; i++) {
            char s[4];
            s[0] = S[i];
            s[1] = S[i + step];
            s[2] = S[i + step * 2];
            s[3] = '\0';
            if (strcmp(s, "RGB") == 0 || strcmp(s, "RBG") == 0 || strcmp(s, "BGR") == 0 ||
                strcmp(s, "BRG") == 0 || strcmp(s, "GBR") == 0 || strcmp(s, "GRB") == 0) {
                sum++;
            }
        }
    }

    printf("%d\n", rNum * gNum * bNum - sum);
    return 0;
}

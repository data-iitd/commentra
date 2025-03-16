
#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    int N;
    char S[1000];
    scanf("%d", &N);
    scanf("%s", S);
    int rNum = 0, gNum = 0, bNum = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'R') {
            rNum++;
        } else if (S[i] == 'G') {
            gNum++;
        } else if (S[i] == 'B') {
            bNum++;
        }
    }
    int sum = 0;
    for (int step = 1; step <= ceil(N / 2.0); step++) {
        for (int i = 0; i < N - step * 2; i++) {
            char s[4];
            s[0] = S[i];
            s[1] = S[i + step];
            s[2] = S[i + step * 2];
            s[3] = '\0';
            if (strcmp(s, "RGB") == 0 || strcmp(s, "RBG") == 0 || strcmp(s, "BGR") == 0 || strcmp(s, "BRG") == 0 || strcmp(s, "GBR") == 0 || strcmp(s, "GRB") == 0) {
                sum++;
            }
        }
    }
    printf("%d\n", rNum * gNum * bNum - sum);
    return 0;
}
// END-OF-CODE
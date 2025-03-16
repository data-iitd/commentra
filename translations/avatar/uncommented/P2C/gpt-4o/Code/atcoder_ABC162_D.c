#include <stdio.h>
#include <string.h>
#include <math.h>

int count_char(const char *s, char c) {
    int count = 0;
    while (*s) {
        if (*s == c) {
            count++;
        }
        s++;
    }
    return count;
}

int is_rgb_permutation(const char *s) {
    return (strcmp(s, "RGB") == 0 || strcmp(s, "RBG") == 0 ||
            strcmp(s, "BGR") == 0 || strcmp(s, "BRG") == 0 ||
            strcmp(s, "GBR") == 0 || strcmp(s, "GRB") == 0);
}

void calculate(int n, const char *s) {
    int rNum = count_char(s, 'R');
    int gNum = count_char(s, 'G');
    int bNum = count_char(s, 'B');
    int sum = 0;

    for (int step = 1; step <= ceil(n / 2.0); step++) {
        for (int i = 0; i <= n - 2 * step; i++) {
            char temp[4];
            temp[0] = s[i];
            temp[1] = s[i + step];
            temp[2] = s[i + 2 * step];
            temp[3] = '\0'; // Null-terminate the string

            if (is_rgb_permutation(temp)) {
                sum++;
            }
        }
    }
    printf("%d\n", rNum * gNum * bNum - sum);
}

int main() {
    int N;
    scanf("%d", &N);
    char S[100]; // Assuming the maximum length of S is 100
    scanf("%s", S);
    calculate(N, S);
    return 0;
}

// <END-OF-CODE>

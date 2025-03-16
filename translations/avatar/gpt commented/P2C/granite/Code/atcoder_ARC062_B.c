
#include <stdio.h>
#include <string.h>

int main() {
    char s[100001];
    scanf("%s", s);

    int num_g = 0, num_p = 0, score = 0;
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        if (s[i] == 'g') {
            if (num_g - num_p > 0) {
                score += 1;
                num_p += 1;
            } else {
                num_g += 1;
            }
        } else if (s[i] == 'p') {
            if (num_g - num_p > 0) {
                num_p += 1;
            } else {
                score -= 1;
                num_g += 1;
            }
        }
    }

    printf("%d\n", score);

    return 0;
}

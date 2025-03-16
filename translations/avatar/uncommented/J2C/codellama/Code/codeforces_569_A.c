#include <stdio.h>

int main() {
    int T, S, q, answer;
    scanf("%d %d %d", &T, &S, &q);
    answer = 0;
    while (S < T) {
        answer++;
        S *= q;
    }
    printf("%d\n", answer);
    return 0;
}


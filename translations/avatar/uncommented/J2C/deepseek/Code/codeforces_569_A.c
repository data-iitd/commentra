#include <stdio.h>

int main() {
    int T, S, q;
    long previous = S;
    int answer = 0;

    scanf("%d %d %d", &T, &S, &q);

    while (previous < T) {
        answer++;
        previous *= q;
    }

    printf("%d\n", answer);

    return 0;
}


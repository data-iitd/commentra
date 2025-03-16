
#include <stdio.h>

int main() {
    int T, S, q, previous, answer;
    scanf("%d %d %d", &T, &S, &q);
    previous = S;
    answer = 0;
    while (previous < T) {
        previous *= q;
        answer++;
    }
    printf("%d\n", answer);
    return 0;
}


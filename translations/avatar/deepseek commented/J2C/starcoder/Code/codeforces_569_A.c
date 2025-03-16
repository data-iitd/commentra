
#include <stdio.h>
#include <stdlib.h>

int main() {
    int T, S, q, answer;
    scanf("%d %d %d", &T, &S, &q);
    previous = S;
    answer = 0;
    while (previous < T) {
        previous *= q;
        answer++;
    }
    printf("%d", answer);
    return 0;
}


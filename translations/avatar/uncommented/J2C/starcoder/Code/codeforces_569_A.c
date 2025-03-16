#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T, S, q, answer;
    long previous;
    scanf("%d %d %d", &T, &S, &q);
    previous = S;
    answer = 0;
    while (previous < T)
    {
        answer++;
        previous *= q;
    }
    printf("%d", answer);
    return 0;
}

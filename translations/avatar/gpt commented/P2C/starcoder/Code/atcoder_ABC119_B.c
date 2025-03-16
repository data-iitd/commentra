#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    scanf("%d", &N);
    float x[N];
    for (int i = 0; i < N; i++)
    {
        char s[100];
        scanf("%s", s);
        if (strcmp(s, "JPY") == 0)
        {
            scanf("%f", &x[i]);
        }
        else if (strcmp(s, "BTC") == 0)
        {
            scanf("%f", &x[i]);
            x[i] *= 380000.0;
        }
    }
    float sum = 0.0;
    for (int i = 0; i < N; i++)
    {
        sum += x[i];
    }
    printf("%f\n", sum);
    return 0;
}


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    scanf("%d", &N);
    double x[N];
    for (int i = 0; i < N; i++)
    {
        char s[100];
        scanf("%s", s);
        if (strstr(s, "JPY"))
        {
            x[i] = atof(s) * 1.0;
        }
        else if (strstr(s, "BTC"))
        {
            x[i] = atof(s) * 380000.0;
        }
    }
    double sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += x[i];
    }
    printf("%.2f\n", sum);
    return 0;
}


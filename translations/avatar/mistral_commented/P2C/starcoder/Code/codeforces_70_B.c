#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int n, ans = 1, sumL = 0;
    scanf("%d", &n);
    for (char *s = strtok(stdin, ".?!"); s; s = strtok(NULL, ".?!") )
    {
        int L = strlen(s);
        if (L > n)
        {
            printf("Impossible");
            exit(0);
        }
        if (sumL + L + (sumL > 0) > n)
        {
            ans++;
            sumL = L;
        }
        else
        {
            sumL += L + (sumL > 0);
        }
    }
    printf("%d", ans);
    return 0;
}


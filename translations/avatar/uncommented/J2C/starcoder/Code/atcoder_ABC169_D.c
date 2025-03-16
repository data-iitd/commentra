#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    long n;
    scanf("%ld", &n);
    int sqrt = (int)sqrt(n);
    int answer = 0;
    for (int i = 2; i <= sqrt; i++)
    {
        int count = 0;
        while (0 == (n % i))
        {
            n /= i;
            count++;
        }
        for (int j = 1; count - j >= 0; j++)
        {
            count -= j;
            answer++;
        }
    }
    if (n > 1)
    {
        answer++;
    }
    printf("%d", answer);
    return 0;
}

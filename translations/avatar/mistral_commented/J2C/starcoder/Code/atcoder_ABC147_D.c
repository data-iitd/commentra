
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    long startTime = clock(); // Start time measurement
    int n;
    scanf("%d", &n);
    long A[n];
    for(int i = 0; i < n; i++)
        scanf("%ld", &A[i]);
    long div = (long)pow(10, 9) + 7;
    long ans = 0;
    for(int i = 0; i < 60; i++)
    {
        long a = 0;
        long count1 = 0;
        for(int j = 0; j < n; j++)
        {
            if((A[j] >> i & 1) == 1)
                count1++;
        }
        a = a + count1 * (n - count1);
        for(int j = 0; j < i; j++)
            a = (a << 1) % div;
        ans += a;
        ans %= div;
    }
    printf("%ld\n", ans);
    long endTime = clock(); // End time measurement
    printf("Time taken by the program is : %ld milliseconds\n", endTime - startTime); // Printing the time taken by the program to execute
    return 0;
}


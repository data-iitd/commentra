
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char n[100];
    int a[5] = {10, 100, 1000, 10000, 100000};
    int new = 0;
    int i;
    int j;
    int k;
    int l;
    int m;
    int n_len;
    int a_len;
    int a_index;
    int n_index;
    int n_digit;
    int n_digit_index;
    int n_digit_sum;

    printf("Enter a number: ");
    scanf("%s", n);

    n_len = strlen(n);
    a_len = sizeof(a) / sizeof(a[0]);

    for (i = 0; i < n_len; i++)
    {
        n_digit = n[i] - '0';
        n_digit_sum += n_digit;
    }

    for (j = 0; j < a_len; j++)
    {
        a_index = a[j];
        if (a_index == n_digit_sum)
        {
            printf("10\n");
            break;
        }
    }

    if (j == a_len)
    {
        printf("%d\n", n_digit_sum);
    }

    return 0;
}


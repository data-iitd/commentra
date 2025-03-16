
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int digits[1000001];
    int i, bills = 0;
    char number[1000001];
    scanf("%s", number);
    for (i = 0; i < strlen(number); i++)
        digits[i] = number[i] - '0';
    digits[i] = 0;
    for (i = 0; i <= strlen(number); i++)
    {
        if (digits[i] == 10)
        {
            digits[i + 1]++;
            digits[i] = 0;
        }
        if (digits[i] < 5)
            bills += digits[i];
        else if (digits[i] == 5)
        {
            if (digits[i + 1] >= 5)
                digits[i + 1]++;
            bills += 5;
        }
        else
        {
            digits[i + 1]++;
            bills += 10 - digits[i];
        }
    }
    printf("%d\n", bills);
    return 0;
}


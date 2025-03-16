#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int n;
    scanf("%d", &n);
    int input_array[n][4];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", &input_array[i][0], &input_array[i][1], &input_array[i][2], &input_array[i][3]);
    }
    int outdated[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (input_array[i][0] < input_array[j][0] && input_array[i][1] < input_array[j][1] && input_array[i][2] < input_array[j][2])
            {
                outdated[i] = input_array[i][3];
            }
        }
    }
    int minimum_cost = 100000;
    int input_number = 0;
    for (int i = 0; i < n; i++)
    {
        if (outdated[i] != 1 && input_array[i][3] < minimum_cost)
        {
            minimum_cost = input_array[i][3];
            input_number = i + 1;
        }
    }
    printf("%d", input_number);
    return 0;
}


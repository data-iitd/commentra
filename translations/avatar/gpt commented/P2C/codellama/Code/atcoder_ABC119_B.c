#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int N;
    float x[1000];
    char input[1000];

    // Read the number of currency inputs from the user
    scanf("%d", &N);

    // Create a list of converted currency values
    // For each input, replace 'JPY' with its equivalent in float and 'BTC' with its equivalent in float
    for (int i = 0; i < N; i++)
    {
        scanf("%s", input);
        x[i] = atof(strtok(input, " ")) * atof(strtok(NULL, " "));
    }

    // Calculate and print the total sum of the converted currency values
    float sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += x[i];
    }
    printf("%.2f\n", sum);

    return 0;
}


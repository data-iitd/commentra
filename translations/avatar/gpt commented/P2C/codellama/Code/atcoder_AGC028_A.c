#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N, M, i, j, counter, Flag, Kaburi_Size;
    char S[1000], T[1000];
    int Number_i[1000], Number_j[1000], Number_iMN[1000], Kaburi_i[1000], Kaburi_j[1000];

    // Read the values of N and M from input
    scanf("%d %d", &N, &M);

    // Read the strings S and T from input
    scanf("%s", S);
    scanf("%s", T);

    // Convert strings S and T into lists for easier indexing
    char list_S[1000], list_T[1000];
    strcpy(list_S, S);
    strcpy(list_T, T);

    // Create a list of indices from 0 to N-1
    for (i = 0; i < N; i++)
    {
        Number_i[i] = i;
    }

    // Initialize an empty list to store calculated indices
    for (i = 0; i < N; i++)
    {
        Number_iMN[i] = i * M / N;
    }

    // Create a list of indices from 0 to M-1
    for (j = 0; j < M; j++)
    {
        Number_j[j] = j;
    }

    // Find the common indices between the scaled Number_iMN and Number_j
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            if (Number_iMN[i] == Number_j[j])
            {
                Kaburi_i[i] = i;
                Kaburi_j[j] = j;
            }
        }
    }

    // Initialize a counter for iteration and a flag for mismatch detection
    counter = 0;
    Flag = 0;

    // Get the size of the Kaburi_i list
    Kaburi_Size = sizeof(Kaburi_i) / sizeof(Kaburi_i[0]);

    // Check if the characters at the calculated indices in S and T match
    while (counter <= Kaburi_Size - 1)
    {
        if (list_S[Kaburi_i[counter]] == list_T[Kaburi_j[counter]])
        {
            pass;  // Characters match, continue checking
        }
        else
        {
            Flag = 1;  // Set flag if a mismatch is found
            break;     // Exit the loop on mismatch
        }
        counter += 1;  // Move to the next index
    }

    // Function to calculate the greatest common divisor (GCD) of two numbers
    int gcd(int a, int b)
    {
        while (b > 0)
        {
            a = b;
            b = a % b;
        }
        return a;
    }

    // Output the result based on the flag indicating if a mismatch was found
    if (Flag == 1)
    {
        printf("-1");  // Print -1 if there was a mismatch
    }
    else
    {
        // Print the least common multiple (LCM) of N and M
        printf("%d", N * M / gcd(N, M));
    }

    return 0;
}


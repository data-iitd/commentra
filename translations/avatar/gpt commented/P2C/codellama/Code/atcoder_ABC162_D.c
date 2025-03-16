
#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    // Read the integer input N which represents the length of the string
    int N;
    scanf("%d", &N);

    // Read the string input S which consists of characters 'R', 'G', and 'B'
    char S[N];
    scanf("%s", S);

    // Convert the string into a list of characters for easier manipulation
    char arr[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = S[i];
    }

    // Count the occurrences of each color in the string
    int rNum = 0, gNum = 0, bNum = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == 'R')
        {
            rNum++;
        }
        else if (arr[i] == 'G')
        {
            gNum++;
        }
        else if (arr[i] == 'B')
        {
            bNum++;
        }
    }

    // Initialize a variable to keep track of the number of valid RGB combinations found
    int sum = 0;

    // Loop through possible steps to form combinations of three characters
    for (int step = 1; step <= (int)ceil(N / 2.0); step++)
    {
        // Loop through the string to form combinations based on the current step
        for (int i = 0; i < N - 2 * step; i++)
        {
            // Create a substring of three characters at the current indices
            char s[3];
            s[0] = arr[i];
            s[1] = arr[i + step];
            s[2] = arr[i + step * 2];

            // Check if the formed substring is one of the valid RGB permutations
            if (strcmp(s, "RGB") == 0 || strcmp(s, "RBG") == 0 || strcmp(s, "BGR") == 0 || strcmp(s, "BRG") == 0 || strcmp(s, "GBR") == 0 || strcmp(s, "GRB") == 0)
            {
                // Increment the count of valid combinations found
                sum++;
            }
        }
    }

    // Calculate and print the result: total combinations minus the valid RGB combinations found
    printf("%d\n", rNum * gNum * bNum - sum);

    return 0;
}


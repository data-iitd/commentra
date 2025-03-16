#include <stdio.h>

int main()
{
    // Initialize an empty list to store input characters
    char s[100];

    // Initialize counters for 'g' and 'p' symbols
    int num_g, num_p;

    // Initialize score variable
    int score;

    // Get input from user
    scanf("%s", s);

    // Initialize counters for 'g' and 'p' symbols
    num_g = 0;
    num_p = 0;

    // Initialize score variable
    score = 0;

    // Iterate through each character in the list 's'
    for (int i = 0; s[i] != '\0'; i++)
    {
        // Check if current character is 'g'
        if (s[i] == 'g')
        {
            // Check if number of 'g' symbols is greater than number of 'p' symbols
            if (num_g > num_p)
            {
                // Increment score and number of 'p' symbols
                score += 1;
                num_p += 1;

                // Comment: If there are more 'g' symbols than 'p' symbols, increment score and update number of 'p' symbols
            }
            else
            {
                // Do not change score and increment number of 'g' symbols
                score = score;
                num_g += 1;

                // Comment: If there are less or equal 'g' symbols than 'p' symbols, do not change score and update number of 'g' symbols
            }
        }
        // Check if current character is 'p'
        else if (s[i] == 'p')
        {
            // Check if number of 'g' symbols is greater than number of 'p' symbols
            if (num_g > num_p)
            {
                // Do not change score and increment number of 'p' symbols
                score = score;
                num_p += 1;

                // Comment: If there are more 'g' symbols than 'p' symbols, do not change score and update number of 'p' symbols
            }
            else
            {
                // Decrement score and increment number of 'g' symbols
                score -= 1;
                num_g += 1;

                // Comment: If there are less or equal 'g' symbols than 'p' symbols, decrement score and update number of 'g' symbols
            }
        }
    }

    // Print the final score
    printf("%d", score);

    // Comment: After iterating through all characters in the list 's', print the final score

    return 0;
}


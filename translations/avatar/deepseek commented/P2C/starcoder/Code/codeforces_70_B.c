
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>

int main()
{
    // Take the maximum sentence length as input
    int n;
    scanf("%d", &n);
    
    // Initialize variables to keep track of the number of sentences and their cumulative length
    int ans = 1, sumL = 0;
    
    // Take a string input and split it into sentences using the regular expression [.?!]
    char *s = NULL;
    while (getline(&s, &n, stdin) > 0)
    {
        // Strip leading and trailing whitespace and add a period to the end of the sentence
        s[strlen(s) - 1] = '.';
        
        // Calculate the length of the sentence
        int L = strlen(s);
        
        // Check if the sentence length is greater than 1
        if (L > 1)
        {
            // Check if the sentence length is greater than the maximum allowed length
            if (L > n)
            {
                // If the sentence is too long, print "Impossible" and exit
                printf("Impossible\n");
                exit(0);
            }
            
            // Check if adding the current sentence would exceed the maximum allowed length
            if (sumL + L + (sumL > 0) > n)
            {
                // If adding the sentence would exceed the maximum length, increment the sentence count
                ans++;
                // Reset the cumulative length to the length of the current sentence
                sumL = L;
            }
            else
            {
                // Otherwise, add the length of the current sentence to the cumulative length
                sumL = sumL + L + (sumL > 0);
            }
        }
    }
    
    // Print the total number of sentences
    printf("%d\n", ans);
    
    // Free the memory allocated to the string
    free(s);
    
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Take an integer 'n' as input from the user
    int n;
    scanf("%d", &n);

    // Take a list 'm' as input from the user, where each element is a single character
    char m[100];
    scanf("%s", m);

    // Initialize a boolean variable 'possible' with a default value of True
    int possible = 1;

    // Iterate through each unique character 'i' in the list 'm'
    for (int i = 0; i < strlen(m); i++)
    {
        // Check if the character 'i' appears more than 'n/2 + 1' times in the list 'm'
        if (strchr(m, m[i]) - m >= n / 2 + 1)
        {
            // If the condition is true, set 'possible' to False and break the loop
            possible = 0;
            break;
        }
    }

    // Print 'YES' if 'possible' is still True, otherwise print 'NO'
    printf("%s\n", possible ? "YES" : "NO");

    return 0;
}


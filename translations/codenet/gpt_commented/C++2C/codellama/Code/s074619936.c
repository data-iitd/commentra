#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare variables to hold input string, temporary string for individual characters, and the sum of digits
    char str[100];
    char tmp[100];
    int sum;

    // Infinite loop to continuously accept input until "0" is entered
    while(1)
    {
        // Read input from the user
        scanf("%s", str);

        // Check if the input is "0", if so, exit the loop
        if(strcmp(str, "0") == 0) break;

        // Initialize sum to 0 for the new input string
        sum = 0;

        // Loop through each character in the input string
        for(int i = 0; i < strlen(str); i++)
        {
            // Convert the character to a string
            sprintf(tmp, "%c", str[i]);

            // Convert the string character to an integer
            int num = atoi(tmp);

            // Add the integer value to the sum
            sum += num;
        }
        
        // Output the sum of the digits for the current input string
        printf("%d\n", sum);
    }

    // Return 0 to indicate successful completion of the program
    return 0;
}


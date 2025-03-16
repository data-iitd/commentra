#include <stdio.h>
#include <stdlib.h>

// Main function starts here
int main()
{
    // Initialize variables
    char str[100];
    char tmp[2];
    int sum;

    // Start an infinite loop
    while(1)
    {
        // Read a string from the user input
        scanf("%s", str);

        // Check if the user wants to exit by entering "0"
        if(str[0] == '0' && str[1] == '\0')
        {
            // Exit the loop if user enters "0"
            break;
        }

        // Initialize sum variable to zero
        sum = 0;

        // Iterate through each character in the string
        for(int i=0; str[i] != '\0'; i++)
        {
            // Get the character as a string
            tmp[0] = str[i];
            tmp[1] = '\0';

            // Convert the character to an integer and add it to the sum
            int num = atoi(tmp);
            sum += num;
        }

        // Print the sum of the digits in the string
        printf("%d\n", sum);
    }

    // Return 0 to indicate successful execution
    return 0;
}

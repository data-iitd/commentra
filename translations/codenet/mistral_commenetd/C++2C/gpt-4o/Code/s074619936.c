#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Initialize variables
    char str[100]; // Assuming a maximum length of 99 characters + 1 for null terminator
    int sum;

    // Start an infinite loop
    while(1)
    {
        // Read a string from the user input
        scanf("%s", str);

        // Check if the user wants to exit by entering "0"
        if(strcmp(str, "0") == 0)
        {
            // Exit the loop if user enters "0"
            break;
        }

        // Initialize sum variable to zero
        sum = 0;

        // Iterate through each character in the string
        for(int i = 0; i < strlen(str); i++)
        {
            // Convert the character to an integer and add it to the sum
            int num = str[i] - '0'; // Convert character to integer
            sum += num;
        }

        // Print the sum of the digits in the string
        printf("%d\n", sum);
    }

    // Return 0 to indicate successful execution
    return 0;
}

// <END-OF-CODE>

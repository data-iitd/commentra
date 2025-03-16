#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Declare variables to hold input string and the sum of digits
<<<<<<< HEAD
    char str[100]; // Assuming a maximum length of 99 characters for the input
=======
    char str[100]; // Assuming a maximum length of 99 characters for the input string
>>>>>>> 98c87cb78a (data updated)
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
<<<<<<< HEAD
            // Convert the character to an integer
            int num = str[i] - '0'; // Convert char to int by subtracting '0'

            // Add the integer value to the sum
=======
            // Convert the character to an integer and add it to the sum
            int num = str[i] - '0'; // Convert character to integer by subtracting '0'
>>>>>>> 98c87cb78a (data updated)
            sum += num;
        }
        
        // Output the sum of the digits for the current input string
        printf("%d\n", sum);
    }

    // Return 0 to indicate successful completion of the program
    return 0;
}

// <END-OF-CODE>

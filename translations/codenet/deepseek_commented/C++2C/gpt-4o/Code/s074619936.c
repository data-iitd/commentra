#include <stdio.h> // Include the standard I/O library
#include <stdlib.h> // Include the standard library for atoi function
<<<<<<< HEAD
#include <string.h> // Include the string library for string manipulation
=======
#include <string.h> // Include string library for string manipulation
>>>>>>> 98c87cb78a (data updated)

int main()
{
    char str[100]; // Declare a character array to store user input
    int sum; // Declare an integer variable to store the sum of digits

    // Infinite loop that continues until the user inputs "0"
    while(1)
    {
        scanf("%s", str); // Read a string from the user
        if(strcmp(str, "0") == 0) break; // If the input string is "0", break the loop
        sum = 0; // Initialize sum to 0
        for(int i = 0; i < strlen(str); i++) // Loop through each character in the string
        {
<<<<<<< HEAD
            int num = str[i] - '0'; // Convert the character to an integer
=======
            char tmp[2]; // Temporary character array to hold the character
            tmp[0] = str[i]; // Assign the character to the temporary array
            tmp[1] = '\0'; // Null-terminate the string
            int num = atoi(tmp); // Convert the string to an integer
>>>>>>> 98c87cb78a (data updated)
            sum += num; // Add the integer to the sum
        }
        
        printf("%d\n", sum); // Print the sum
    }
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>

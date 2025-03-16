#include <stdio.h>
#include <stdlib.h> // Include the standard library for atoi function

int main()
{
    char str[100]; // Declare a character array to store user input
    char tmp[2]; // Declare a temporary character array for character conversion
    int sum; // Declare an integer variable to store the sum of digits

    // Infinite loop that continues until the user inputs "0"
    while(1)
    {
        scanf("%s", str); // Read a string from the user
        if(str[0] == '0' && str[1] == '\0') break; // If the input string is "0", break the loop
        sum = 0; // Initialize sum to 0
        for(int i=0; str[i] != '\0'; i++) // Loop through each character in the string
        {
            tmp[0] = str[i]; // Copy the character to the temporary array
            tmp[1] = '\0'; // Null-terminate the temporary array
            int num = atoi(tmp); // Convert the temporary array to an integer
            sum += num; // Add the integer to the sum
        }
        
        printf("%d\n", sum); // Print the sum
    }
    return 0; // Return 0 to indicate successful execution
}

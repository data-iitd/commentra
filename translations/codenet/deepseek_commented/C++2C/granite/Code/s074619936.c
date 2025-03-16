
#include <stdio.h>
#include <stdlib.h> // Include the standard library for atoi function

int main()
{
    char str[100]; // Declare a character array variable to store user input
    char tmp[10]; // Declare a temporary character array variable for character conversion
    int sum; // Declare an integer variable to store the sum of digits

    // Infinite loop that continues until the user inputs "0"
    while(1)
    {
        scanf("%s", str); // Read a string from the user
        if(strcmp(str, "0") == 0) break; // If the input string is "0", break the loop
        sum = 0; // Initialize sum to 0
        for(int i=0;i<strlen(str);i++) // Loop through each character in the string
        {
            tmp[0] = str[i]; // Convert the character to a string
            tmp[1] = '\0'; // Null-terminate the string
            int num = atoi(tmp); // Convert the string to an integer
            sum += num; // Add the integer to the sum
        }
        
        printf("%d\n", sum); // Print the sum
    }
    return 0; // Return 0 to indicate successful execution
}

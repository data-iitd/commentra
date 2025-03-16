#include <stdio.h>
#include <stdlib.h>

public class Main {
    public static void main(String[] args) {
        // Declare variables to hold input numbers and intermediate values
        char inputNumbers[5]; // Array to store input numbers as characters
        char temp[2];         // Temporary array to convert characters to integers
        int a, b, c, d;      // Variables to hold the individual numbers
        int sum;             // Variable to hold the calculated sum
        char symbols[3];     // Array to store the symbols used in the expression
        
        // Read a string of numbers from user input
        scanf("%s", &inputNumbers);

        // Set the second character of temp to null terminator for string conversion
        temp[1] = '\0';

        // Convert each character to an integer and store in respective variables
        temp[0] = inputNumbers[0];
        a = atoi(temp);
        temp[0] = inputNumbers[1];
        b = atoi(temp);
        temp[0] = inputNumbers[2];
        c = atoi(temp);
        temp[0] = inputNumbers[3];
        d = atoi(temp);
        
        // Iterate through all combinations of addition and subtraction for the four numbers
        for (int i = 0; i < 2; i++) // Loop for the first operation (a + b or a - b)
        {
            for (int j = 0; j < 2; j++) // Loop for the second operation (result + c or result - c)
            {
                for (int k = 0; k < 2; k++) // Loop for the third operation (result + d or result - d)
                {
                    // Determine the first operation (addition or subtraction with a and b)
                    if (i == 0)
                    {
                        sum = a + b; // Perform addition
                        symbols[0] = '+'; // Store the symbol used
                    }
                    else
                    {
                        sum = a - b; // Perform subtraction
                        symbols[0] = '-'; // Store the symbol used
                    }

                    // Determine the second operation (addition or subtraction with c)
                    if (j == 0)
                    {
                        sum = sum + c; // Perform addition
                        symbols[1] = '+'; // Store the symbol used
                    }
                    else
                    {
                        sum = sum - c; // Perform subtraction
                        symbols[1] = '-'; // Store the symbol used
                    }

                    // Determine the third operation (addition or subtraction with d)
                    if (k == 0)
                    {
                        sum = sum + d; // Perform addition
                        symbols[2] = '+'; // Store the symbol used
                    }
                    else
                    {
                        sum = sum - d; // Perform subtraction
                        symbols[2] = '-'; // Store the symbol used
                    }

                    // Check if the calculated sum equals 7
                    if (sum == 7)
                    {
                        // Print the expression that results in 7
                        printf("%d%c%d%c%d%c%d=7\n", a, symbols[0], b, symbols[1], c, symbols[2], d);
                        
                        return 0; // Exit the program after finding the first valid expression
                    }
                }
            }
        }

        return 0; // Return 0 to indicate successful execution
    }
}


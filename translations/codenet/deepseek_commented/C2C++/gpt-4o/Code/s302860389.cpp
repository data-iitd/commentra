#include <iostream>
#include <cstdlib>
#include <string>

int main()
{
    // Array to store the input numbers as characters
    char inputNumbers[5];
    // Temporary array to hold individual digits
    char temp[2];
    // Integer variables to store the digits
    int a, b, c, d;
    // Variable to store the intermediate results
    int sum;
    // Array to store the operators
    char symbols[3];
    
    // Read a string of four characters from the input
    std::cin >> inputNumbers;

    // Initialize the second element of temp to the null character
    temp[1] = '\0';

    // Extract each digit from inputNumbers and convert it to an integer
    temp[0] = inputNumbers[0];
    a = atoi(temp);
    temp[0] = inputNumbers[1];
    b = atoi(temp);
    temp[0] = inputNumbers[2];
    c = atoi(temp);
    temp[0] = inputNumbers[3];
    d = atoi(temp);
    
    // Nested loop structure to explore all combinations of addition and subtraction
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                // Choose the operation based on the value of i
                if (i == 0)
                {
                    sum = a + b;
                    symbols[0] = '+';
                }
                else
                {
                    sum = a - b;
                    symbols[0] = '-';
                }

                // Choose the operation based on the value of j
                if (j == 0)
                {
                    sum = sum + c;
                    symbols[1] = '+';
                }
                else
                {
                    sum = sum - c;
                    symbols[1] = '-';
                }

                // Choose the operation based on the value of k
                if (k == 0)
                {
                    sum = sum + d;
                    symbols[2] = '+';
                }
                else
                {
                    sum = sum - d;
                    symbols[2] = '-';
                }

                // Check if the sum equals 7
                if (sum == 7)
                {
                    // Print the expression if the sum is 7
                    std::cout << a << symbols[0] << b << symbols[1] << c << symbols[2] << d << "=7" << std::endl;
                    
                    // Exit the program with a return value of 0
                    return 0;
                }
            }
        }
    }

    // Return 0 if no combination results in a sum of 7
    return 0;
}

// <END-OF-CODE>

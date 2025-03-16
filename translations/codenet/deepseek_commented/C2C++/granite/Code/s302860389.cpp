
#include <iostream>
#include <string>

// Main function where the program execution begins
int main()
{
    // String to store the input numbers
    std::string inputNumbers;
    // Integer variables to store the digits
    int a, b, c, d;
    // Variable to store the intermediate results
    int sum;
    // String to store the operators
    std::string symbols;
    
    // Read a string of four characters from the input
    std::cin >> inputNumbers;

    // Extract each digit from inputNumbers and convert it to an integer
    a = inputNumbers[0] - '0';
    b = inputNumbers[1] - '0';
    c = inputNumbers[2] - '0';
    d = inputNumbers[3] - '0';
    
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
                    symbols = "+";
                }
                else
                {
                    sum = a - b;
                    symbols = "-";
                }

                // Choose the operation based on the value of j
                if (j == 0)
                {
                    sum = sum + c;
                    symbols = symbols + "+";
                }
                else
                {
                    sum = sum - c;
                    symbols = symbols + "-";
                }

                // Choose the operation based on the value of k
                if (k == 0)
                {
                    sum = sum + d;
                    symbols = symbols + "+";
                }
                else
                {
                    sum = sum - d;
                    symbols = symbols + "-";
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



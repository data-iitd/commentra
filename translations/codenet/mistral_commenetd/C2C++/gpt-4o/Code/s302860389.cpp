#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

// Declare variables
char inputNumbers[5];
char temp[2];
int a, b, c, d;
int sum;
char symbols[3];

int main()
{
    // Initialize variables
    char inputNumbers[5] = {0};
    char temp[2] = {0};
    int a, b, c, d;
    int sum;
    char symbols[3] = {'+', '+', '+'};

    // Read input numbers from user
    cout << "Enter four integers separated by spaces: ";
    cin >> inputNumbers;

    // Extract each number from input string and convert to integer
    temp[1] = '\0';

    temp[0] = inputNumbers[0];
    a = atoi(temp);
    temp[0] = inputNumbers[1];
    b = atoi(temp);
    temp[0] = inputNumbers[2];
    c = atoi(temp);
    temp[0] = inputNumbers[3];
    d = atoi(temp);

    // Perform arithmetic operations and check for the sum equal to 7
    for (int i = 0; i < 2; i++) // outer loop
    {
        for (int j = 0; j < 2; j++) // middle loop
        {
            for (int k = 0; k < 2; k++) // inner loop
            {
                // Assign symbols based on the position of current number
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

                // Check if the sum is equal to 7
                if (sum == 7)
                {
                    cout << a << symbols[0] << b << symbols[1] << c << symbols[2] << d << " = 7" << endl;

                    // If sum is equal to 7, exit the loop and return 0
                    return 0;
                }
            }
        }
    }

    // If no combination of four numbers results in a sum of 7, return 0
    return 0;
}

// <END-OF-CODE>

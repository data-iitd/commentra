#include <stdio.h>
#include <stdlib.h>

# Main function where the program execution begins
def main():
    # Array to store the input numbers as characters
    inputNumbers = [None] * 5
    # Temporary array to hold individual digits
    temp = [None] * 2
    # Integer variables to store the digits
    a = 0
    b = 0
    c = 0
    d = 0
    # Variable to store the intermediate results
    sum = 0
    # Array to store the operators
    symbols = [None] * 3

    # Read a string of four characters from the input
    scanf("%s", &inputNumbers)

    # Initialize the second element of temp to the null character
    temp[1] = '\0'

    # Extract each digit from inputNumbers and convert it to an integer
    temp[0] = inputNumbers[0]
    a = atoi(temp)
    temp[0] = inputNumbers[1]
    b = atoi(temp)
    temp[0] = inputNumbers[2]
    c = atoi(temp)
    temp[0] = inputNumbers[3]
    d = atoi(temp)
    
    # Nested loop structure to explore all combinations of addition and subtraction
    for i in range(2):
        for j in range(2):
            for k in range(2):
                # Choose the operation based on the value of i
                if (i == 0):
                    sum = a + b
                    symbols[0] = '+'
                else:
                    sum = a - b
                    symbols[0] = '-'

                # Choose the operation based on the value of j
                if (j == 0):
                    sum = sum + c
                    symbols[1] = '+'
                else:
                    sum = sum - c
                    symbols[1] = '-'

                # Choose the operation based on the value of k
                if (k == 0):
                    sum = sum + d
                    symbols[2] = '+'
                else:
                    sum = sum - d
                    symbols[2] = '-'

                # Check if the sum equals 7
                if (sum == 7):
                    # Print the expression if the sum is 7
                    printf("%d%c%d%c%d%c%d=7\n", a, symbols[0], b, symbols[1], c, symbols[2], d)
                    
                    # Exit the program with a return value of 0
                    return 0

    # Return 0 if no combination results in a sum of 7
    return 0

# 
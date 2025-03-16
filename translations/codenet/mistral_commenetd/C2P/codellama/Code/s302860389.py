
#include <stdio.h>
#include <stdlib.h>

# Declare variables
inputNumbers = [0] * 5
temp = [0] * 2
a, b, c, d = 0, 0, 0, 0
sum = 0
symbols = ['+', '+', '+']

def main():
    # Read input numbers from user
    print("Enter four integers separated by spaces: ")
    inputNumbers = input()

    # Extract each number from input string and convert to integer
    temp[1] = '\0'

    temp[0] = inputNumbers[0]
    a = int(temp)
    temp[0] = inputNumbers[1]
    b = int(temp)
    temp[0] = inputNumbers[2]
    c = int(temp)
    temp[0] = inputNumbers[3]
    d = int(temp)

    # Perform arithmetic operations and check for the sum equal to 7
    for i in range(2): # outer loop
        for j in range(2): # middle loop
            for k in range(2): # inner loop
                # Assign symbols based on the position of current number
                if i == 0:
                    sum = a + b
                    symbols[0] = '+'
                else:
                    sum = a - b
                    symbols[0] = '-'

                if j == 0:
                    sum = sum + c
                    symbols[1] = '+'
                else:
                    sum = sum - c
                    symbols[1] = '-'

                if k == 0:
                    sum = sum + d
                    symbols[2] = '+'
                else:
                    sum = sum - d
                    symbols[2] = '-'

                # Check if the sum is equal to 7
                if sum == 7:
                    print("%d%c%d%c%d%c%d = 7\n" % (a, symbols[0], b, symbols[1], c, symbols[2], d))

                    # If sum is equal to 7, exit the loop and return 0
                    return 0

    # If no combination of four numbers results in a sum of 7, return 0
    return 0


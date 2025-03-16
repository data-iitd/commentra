#include<stdio.h>
#define N 2000

# Declare global variables
num1 = 0
math = [0] * (N + 1)

def main():
    # Declare variables for input and calculations
    a = 0
    num2 = 0
    ans = 0
    sum = 0
    i = 0
    j = 0

    # Initialize the first element of the math array to 1
    math[0] = 1

    # Read the number of elements for the first set
    num1 = int(input())

    # Loop to read each element and update the possible sums
    for i in range(num1):
        a = int(input()) # Read the current element
        sum += a # Update the total sum

        # Update the math array to reflect the new possible sums
        for j in range(sum - a, -1, -1):
            if math[j] == 1:
                math[j + a] = 1 # Mark the new sum as possible

    # Read the number of queries for possible sums
    num2 = int(input())

    # Loop to check if each queried sum is possible
    for i in range(num2):
        ans = int(input()) # Read the queried sum
        # Check if the queried sum is possible and print the result
        if math[ans] == 1:
            print("yes")
        else:
            print("no")

if __name__ == "__main__":
    main()


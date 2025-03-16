#include <iostream>
#include <cmath>
using namespace std;

# Function prototype for div
def div(n):
    # Check if n is even, return 2 if it is
    if n % 2 == 0:
        return 2

    # Calculate the square root of n for optimization
    s = math.sqrt(n)
    
    # Check for odd divisors from 3 up to the square root of n
    for i in range(3, int(s) + 1, 2):
        # If i is a divisor of n, return it
        if n % i == 0:
            return i

    # If no divisors found, return n (n is prime)
    return n


# Main function
def main():
    num = int(input("Enter a number: ")) # Read an integer from the user
    print(num, ":") # Output the initial number followed by a colon

    # Loop until num is reduced to 1
    while num != 1:
        # Find and output the smallest divisor of num
        print(" ", div(num), end="")
        # Divide num by its smallest divisor
        num = num // div(num)
    print() # Print a newline at the end of output


# Call the main function
main()



#include <stdio.h>

# Declare variables
a, b, n, sum = 0
i, j = 0

def main():
    # Initialize variables
    while True:
        # Read input values a, b, and n from the user
        try:
            a, b, n = map(int, input().split())
        except:
            # Break the loop if the input is invalid
            break

        # Calculate a = a - a/b * b
        a -= a // b * b

        # Initialize sum to zero
        sum = 0

        # Perform the main calculation for n times
        for i in range(1, n + 1):
            # Multiply a by 10
            a *= 10

            # Find the largest multiple of b less than or equal to a
            for j in range(9, -1, -1):
                # Check if b*j is less than or equal to a
                if b * j <= a:
                    # Subtract the multiple of b from a
                    a -= b * j

                    # Add the digit j to the sum
                    sum += j

                    # Break the inner loop since we have found the largest multiple
                    break

        # Print the result
        print(sum)

# Return 0 to indicate successful execution
if __name__ == "__main__":
    main()


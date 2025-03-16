#include <stdio.h>

def main():
    # Declare two integer variables x and y
    x = 0
    y = 0

    # Read two integers from the user using scanf function and store them in variables x and y respectively
    x = int(input())
    y = int(input())

    # Print the product of x and y and the sum of 2 times x and 2 times y using printf function
    print(x * y, (2*x) + (2*y))

if __name__ == "__main__":
    main()

#
#include <stdio.h>  # Include the standard input/output library

def main():
    A, B, flag = 0, 0, 0  # Declare integer variables A, B, and flag
    A, B = input().split()  # Read input values for A and B

    # Loop through numbers 1 to 3 to check if the product of A, B, and i is odd
    for i in range(1, 4):
        if (A * B * i) % 2 == 1:  # Check if the product is odd
            flag = 1  # Set flag to 1 if an odd product is found
            break  # Break out of the loop

    if flag:
        print("Yes")  # Print "Yes" if an odd product was found
    else:
        print("No")  # Print "No" if no odd product was found

if __name__ == "__main__":
    main()


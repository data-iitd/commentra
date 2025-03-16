# Include necessary libraries
import sys

def main():
    # Declare variables A, B, C, and X
    A = int(input())
    B = int(input())
    C = int(input())
    X = int(input())

    # Divide X by 50
    X = X // 50

    # Initialize counter
    kosu = 0

    # Three nested loops to check if X can be represented as 10*i + 2*j + k
    for i in range(A + 1):  # Loop through all possible values of i from 0 to A
        for j in range(B + 1):  # Loop through all possible values of j from 0 to B
            for k in range(C + 1):  # Loop through all possible values of k from 0 to C
                if X == (10 * i) + (2 * j) + k:  # Check if X equals the sum of 10*i, 2*j, and k
                    kosu += 1  # If so, increment the counter kosu

    # Print the result
    print(kosu)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

# Importing the necessary module for input
import sys

def main():
    # Reading input values
    Q = int(sys.stdin.readline().strip())  # Reading the first long value Q
    H = int(sys.stdin.readline().strip())  # Reading the second long value H
    S = int(sys.stdin.readline().strip())  # Reading the third long value S
    D = int(sys.stdin.readline().strip())  # Reading the fourth long value D
    N = int(sys.stdin.readline().strip())  # Reading the fifth long value N

    # Calculating the minimum price per item
    one_price = min(Q * 4, H * 2, S)

    # Checking if the minimum price per item is less than or equal to half of the deposit amount
    if one_price <= D / 2:
        print(N * one_price)  # Printing the result as the product of N and the minimum price per item
    else:
        # Calculating and printing the result for the other case
        print((N // 2) * D + (N % 2) * one_price)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

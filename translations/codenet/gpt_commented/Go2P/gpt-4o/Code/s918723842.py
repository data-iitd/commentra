import sys
import math

def main():
    # Read three integers from input: H, W, and N
    H, W, N = map(int, sys.stdin.readline().split())

    # Calculate the maximum of H and W
    A = max(H, W)

    # Calculate and print the number of full groups needed to accommodate N items
    print((N + A - 1) // A)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

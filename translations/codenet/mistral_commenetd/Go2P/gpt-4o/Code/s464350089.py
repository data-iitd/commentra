# Constants
MOD = 1000000007
IO_BUFFER_SIZE = 1024 * 1024  # 1MB

# Helper function to read input
import sys

def read_input():
    return sys.stdin.read().split()

def main():
    # Reading the first two integers h and n
    data = read_input()
    h = int(data[0])
    n = int(data[1])

    # Initializing variable a to 0
    a = 0

    # Iterating through the array of size n and adding each integer to variable a
    for i in range(2, 2 + n):
        a += int(data[i])

    # Checking if h is less than or equal to the sum of all integers and printing the result accordingly.
    if h > a:
        print("No")
    else:
        print("Yes")

if __name__ == "__main__":
    main()

# <END-OF-CODE>

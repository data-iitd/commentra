# Importing necessary packages
import sys

# Declaring variables
def main():
    # Reading input values from standard input
    x, a, b = map(int, sys.stdin.readline().split())

    # Logic block to check if b is less than or equal to a
    if b - a <= 0:
        print("delicious")
    elif b - a <= x:
        print("safe")
    else:
        print("dangerous")

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>

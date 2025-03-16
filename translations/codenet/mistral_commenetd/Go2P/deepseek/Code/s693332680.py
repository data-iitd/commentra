# Importing necessary packages
import sys

# Declaring variables
def main():
    x, a, b = map(int, sys.stdin.readline().split())

    # Logic block to check if b is less than or equal to a
    if b - a <= 0:
        print("delicious")
    # Next case: If b is greater than a but less than or equal to x
    elif b - a <= x:
        print("safe")
    # Default case: If none of the above conditions are met
    else:
        print("dangerous")

# Calling the main function
if __name__ == "__main__":
    main()

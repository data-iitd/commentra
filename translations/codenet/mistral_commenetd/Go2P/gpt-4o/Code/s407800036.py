# Import the sys module for standard input
import sys

def main():
    # Read three integers from the standard input
    A, B, C = map(int, sys.stdin.readline().split())

    # Check if the value of C is within the range of A and B
    if A <= C <= B:
        # If it is, print "Yes" to the standard output
        print("Yes")
    else:
        # Otherwise, print "No" to the standard output
        print("No")

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>

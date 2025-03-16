# Import the sys module for reading input
import sys

def main():
    # Read three integers from the standard input and assign them to the variables
    a, b, c = map(int, sys.stdin.readline().split())

    # Check if the difference between "b" and "a" is equal to the difference between "c" and "b"
    if b - a == c - b:
        # If the condition is true, print "YES" to the standard output
        print("YES")
    else:
        # If the condition is false, print "NO" to the standard output
        print("NO")

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>

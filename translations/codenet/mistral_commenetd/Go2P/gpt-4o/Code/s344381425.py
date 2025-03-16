# Import the sys module for standard input
import sys

def main():
    # Read three integers from standard input
    a, b, c = map(int, sys.stdin.readline().split())

    # Check if the condition "a < b and b < c" is true
    if a < b and b < c:
        # If the condition is true, print "Yes"
        print("Yes")
    else:
        # If the condition is false, print "No"
        print("No")

# Call the main function
if __name__ == "__main__":
    main()

# End of code

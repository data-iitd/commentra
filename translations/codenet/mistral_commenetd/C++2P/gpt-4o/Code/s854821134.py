# Import necessary libraries
import sys

# Define a constant for infinity
INF = 200000005

def main():
    # Read two integers from standard input
    a, b = map(int, sys.stdin.readline().split())

    # Check if both a and b are less than or equal to 8
    if a <= 8 and b <= 8:
        print("Yay!")  # If the condition is true, print "Yay!"
    else:
        print(":(")  # If the condition is false, print ":("

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>

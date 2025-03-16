# Include the necessary libraries for input/output operations, string manipulation, and dynamic arrays
import sys

# Define a constant integer INF for use later
INF = 200000005

# Begin the main function
def main():
    # Read the values of a and b from the standard input
    a, b = map(int, sys.stdin.readline().split())

    # Check if both a and b are less than or equal to 8
    if a <= 8 and b <= 8:
        # If the condition is true, print "Yay!" to the standard output
        print("Yay!")
    else:
        # If the condition is false, print ":(" to the standard output
        print(":( ")

# Call the main function
if __name__ == "__main__":
    main()

# End the main function and indicate the end of the code with "<END-OF-CODE>".
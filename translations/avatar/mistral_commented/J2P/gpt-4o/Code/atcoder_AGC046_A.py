# Importing necessary libraries
import sys

# Main function starts here
def main():
    # Reading the first integer input
    x = int(sys.stdin.readline().strip())

    # Initializing count variable to 0
    count = 0

    # Initializing temporary variable tmp with the value of x
    tmp = x

    # Setting x to 0
    x = 0

    # Starting a while loop that runs until x is equal to 360
    while x != 360:
        # Adding the value of tmp to x
        x += tmp

        # If x is greater than 360, then subtract 360 from it
        if x > 360:
            x -= 360

        # Incrementing the count variable
        count += 1

    # Printing the value of count to the console
    print(count)

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>

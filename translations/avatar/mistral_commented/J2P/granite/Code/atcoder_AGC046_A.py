
# Importing necessary Python libraries
import sys

# Main function starts here
def main():

    # Creating FastReader object to read input
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')

    # Reading the first integer input
    x = int(input())

    # Initializing count variable to 0
    count = 0

    # Initializing temporary variable tmp with the value of x
    tmp = x

    # Setting x to 0
    x = 0

    # Starting a while loop that runs until x is equal to 360
    while x!= 360:

        # Adding the value of tmp to x
        x = x + tmp

        # If x is greater than 360, then subtract 360 from it
        if x > 360:
            x = x - 360

        # Incrementing the count variable
        count = count + 1

    # Printing the value of count to the console using sys.stdout
    sys.stdout.write(str(count) + "\n")

    # Closing the sys.stdin and sys.stdout objects
    sys.stdin.close()
    sys.stdout.close()

# Calling the main function
if __name__ == "__main__":
    main()


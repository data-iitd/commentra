
# Import Scanner class for reading input
from java.util import Scanner

# Entry point of the Java application
def main(args):
    # Create a new Scanner object to read input from standard input
    sc = Scanner(System.in)

    # Read the first integer from standard input and convert it to an integer
    a = int(sc.next())

    # Read the second integer from standard input and convert it to an integer
    b = int(sc.next())

    # Initialize sum variable to 0
    sum = 0

    # Iterate through two iterations
    for i in range(2):
        # Check if a is greater than or equal to b
        if a >= b:
            # Add a to sum and decrement a by 1
            sum += a
            a -= 1
        else:
            # Add b to sum and decrement b by 1
            sum += b
            b -= 1

    # Print the value of sum to standard output
    print(sum)

# 
# Import the sys module for reading input
import sys

def main():
    # Read the first integer from standard input and convert it to an integer
    a = int(sys.stdin.readline().strip())
    # Read the second integer from standard input and convert it to an integer
    b = int(sys.stdin.readline().strip())

    sum = 0  # Initialize sum variable to 0

    for i in range(2):  # Iterate through two iterations
        if a >= b:  # Check if a is greater than or equal to b
            sum += a  # Add a to sum
            a -= 1  # Decrement a by 1
        else:
            sum += b  # Add b to sum
            b -= 1  # Decrement b by 1

    print(sum)  # Print the value of sum to standard output

if __name__ == "__main__":
    main()

# <END-OF-CODE>

# Python code to perform the same operations as the provided Go code

# Import necessary modules
import sys

# Main function
def main():
    # Read the first line from standard input
    sage = input()

    # Use a match statement to determine the action based on the first line read
    match sage:
        case "1":
            # Print "Hello World" if the first line is "1"
            print("Hello World")
        case "2":
            # Initialize a variable named 'sum' to store the sum of two numbers
            sum = 0

            # Use a for loop to read and sum two numbers
            for i in range(2):
                # Read the next line from standard input
                num = input()

                # Convert the next line to an integer and store it in a variable named 'num'
                num = int(num)

                # Add the current number to the sum
                sum += num

            # Print the sum of the two numbers
            print(sum)

# Call the main function
if __name__ == "__main__":
    main()


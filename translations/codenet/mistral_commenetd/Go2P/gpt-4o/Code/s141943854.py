import sys

# Function to check for errors and exit with error message if any
def check(e):
    if e:
        sys.exit(f"error: {e}")

# Main function
def main():
    # Read the first line from standard input
    sage = input().strip()

    # Use a conditional statement to determine the action based on the first line read
    if sage == "1":
        # Print "Hello World" if the first line is "1"
        print("Hello World")
    elif sage == "2":
        # Initialize a variable named 'sum' to store the sum of two numbers
        total_sum = 0

        # Use a loop to read and sum two numbers
        for _ in range(2):
            # Read the next line from standard input
            try:
                num = int(input().strip())
            except ValueError as e:
                check(e)

            # Add the current number to the sum
            total_sum += num

        # Print the sum of the two numbers
        print(total_sum)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>

import sys

# Function to read an integer as input
def scan_int():
    return int(scan_string())  # Convert the string to integer

# Function to read a string as input
def scan_string():
    return next(input_iterator)  # Read the next token as a string

# Function to read an array of integers as input
def scan_ints(n):
    return [scan_int() for _ in range(n)]  # Read and store n integers

# Function to read an array of strings as input
def scan_strings(n):
    return [scan_string() for _ in range(n)]  # Read and store n strings

# Initialize the input iterator
input_iterator = iter(sys.stdin.read().split())

# Main function to execute the program
def main():
    # Read the first three integers as input
    r = scan_int()
    D = scan_int()
    x = scan_int()

    # Iterate through a loop 10 times
    for i in range(10):
        # Calculate the new value of x using the given formula
        x = r * x - D

        # Print the value of x to the console
        print(x)

# Execute the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>

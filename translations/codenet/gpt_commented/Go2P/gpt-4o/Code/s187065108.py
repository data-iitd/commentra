import sys

# Function to read an integer from input
def scan_int():
    return int(scan_string())  # Convert the scanned string to an integer

# Function to read a single string from input
def scan_string():
    return next(input_iterator)  # Return the next word from input

# Function to read 'n' integers from input and return them as a list
def scan_ints(n):
    return [scan_int() for _ in range(n)]  # Fill the list with integers read from input

# Function to read 'n' strings from input and return them as a list
def scan_strings(n):
    return [scan_string() for _ in range(n)]  # Fill the list with strings read from input

# Initialize input iterator
input_iterator = iter(sys.stdin.read().split())

# Main function
def main():
    # Read three integers from input: r, D, and x
    r, D, x = scan_int(), scan_int(), scan_int()
    
    # Perform calculations and print the result for 10 iterations
    for _ in range(10):
        x = r * x - D  # Update x based on the formula
        print(x)  # Print the current value of x

if __name__ == "__main__":
    main()

# <END-OF-CODE>

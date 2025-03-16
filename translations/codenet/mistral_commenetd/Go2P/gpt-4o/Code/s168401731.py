import sys

# Function to read the next integer from the input
def get_next_int():
    return int(next(scanner))

# Main function is the entry point of the program
if __name__ == "__main__":
    # Open standard input as default file if no arguments are provided
    if len(sys.argv) > 1:
        input_file = open(sys.argv[1], 'r')
        scanner = iter(input_file.read().split())
    else:
        scanner = iter(sys.stdin.read().split())

    # Read the first integer from the input
    n = get_next_int()

    # Initialize answer variable
    ans = "second"
    # Iterate through the input integers
    for _ in range(n):
        # Read the next integer from the input
        a = get_next_int()
        # Check if the current integer is odd
        if a % 2 == 1:
            # Update the answer if an odd integer is found
            ans = "first"
            # Exit the loop if only one odd integer is found
            break

    # Print the answer to the output
    print(ans)

# <END-OF-CODE>

import sys

def main():
    # Initialize input and output file pointers.
    input_file = sys.stdin
    output_file = sys.stdout

    # Check for command line arguments to open input and output files.
    if len(sys.argv) > 1:
        input_file = open(sys.argv[1], 'r')  # Open input file if provided.
        if len(sys.argv) > 2:
            output_file = open(sys.argv[2], 'w')  # Create output file if provided.

    # Read the number of integers to process.
    n = int(input_file.readline().strip())

    # Initialize the answer as "second" and check for odd integers.
    ans = "second"
    for _ in range(n):
        a = int(input_file.readline().strip())  # Read the next integer.
        if a % 2 == 1:  # Check if the integer is odd.
            ans = "first"  # If odd, set answer to "first".
            break  # Exit the loop early if an odd integer is found.

    # Write the result to the output.
    output_file.write(ans + '\n')

    # Close the files if they were opened.
    if input_file is not sys.stdin:
        input_file.close()
    if output_file is not sys.stdout:
        output_file.close()

# Call the main function.
if __name__ == "__main__":
    main()

# <END-OF-CODE>

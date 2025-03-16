import sys

def main():
    # Check if command-line arguments are provided for file input/output.
    if len(sys.argv) > 1:
        input_file = open(sys.argv[1], 'r')
        if len(sys.argv) > 2:
            output_file = open(sys.argv[2], 'w')
        else:
            output_file = sys.stdout
    else:
        input_file = sys.stdin
        output_file = sys.stdout

    # Read the number of integers to process.
    n = int(input_file.readline().strip())

    # Initialize the answer to "second".
    ans = "second"
    for _ in range(n):
        a = int(input_file.readline().strip())
        if a % 2 == 1:
            ans = "first"
            break

    # Print the result based on the condition.
    print(ans, file=output_file)

    # Close files if they were opened.
    if input_file is not sys.stdin:
        input_file.close()
    if output_file is not sys.stdout:
        output_file.close()

if __name__ == "__main__":
    main()

# <END-OF-CODE>

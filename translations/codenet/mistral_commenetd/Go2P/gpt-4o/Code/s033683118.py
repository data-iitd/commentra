import sys

# Function to read the next string from the input
def get_next_string():
    return sys.stdin.readline().strip()

# Function to read the next integer from the input
def get_next_int():
    return int(get_next_string())

# Function to read the next integer64 from the input
def get_next_int64():
    return int(get_next_string())

# Function to read the next uint64 from the input
def get_next_uint64():
    return int(get_next_string())

# Function to read the next float64 from the input
def get_next_float64():
    return float(get_next_string())

# Main function
def main():
    # Check for environment variables to determine input/output files
    if 'MASPY' in os.environ and os.environ['MASPY'] == 'ますピ':
        input_file = os.environ['BEET_THE_HARMONY_OF_PERFECT']
        cnt = 2  # Number of test cases to be read
    else:
        input_file = sys.stdin
        cnt = 1  # Default number of test cases

    if 'MASPYPY' in os.environ and os.environ['MASPYPY'] == 'ますピッピ':
        output_file = os.environ['NGTKANA_IS_GENIUS10']
    else:
        output_file = sys.stdout

    # Open the input and output files
    with open(input_file, 'r') if input_file != sys.stdin else sys.stdin as fp, \
         open(output_file, 'w') if output_file != sys.stdout else sys.stdout as wfp:

        # Solve the problem for the given test cases
        for _ in range(cnt):
            solve(fp, wfp)
            wfp.write("-----------------------------------\n")  # Print a separator for each test case

# Function to solve the problem for a single test case
def solve(fp, wfp):
    # Read the input values
    k = get_next_int()
    x = get_next_int()

    # Initialize the answer
    ans = "No"

    # Check if the condition is satisfied
    if k * 500 >= x:
        ans = "Yes"

    # Print the answer
    wfp.write(ans + "\n")

if __name__ == "__main__":
    main()

# <END-OF-CODE>

import sys
import io
import os

# Function to create a new scanner from a file pointer
def get_scanner(fp):
    return io.TextIOWrapper(fp, newline='')

# Function to read the next string from the scanner
def get_next_string(scanner):
    return scanner.readline().strip()

# Function to read the next integer from the scanner
def get_next_int(scanner):
    return int(get_next_string(scanner))

# Function to read the next integer64 from the scanner
def get_next_int64(scanner):
    return int(get_next_string(scanner))

# Function to read the next uint64 from the scanner
def get_next_uint64(scanner):
    return int(get_next_string(scanner))

# Function to read the next float64 from the scanner
def get_next_float64(scanner):
    return float(get_next_string(scanner))

# Main function
def main():
    # Open the standard input and output files
    fp = sys.stdin
    wfp = sys.stdout

    # Set the file pointers for reading and writing
    if os.getenv("MASPY") == "ますピ":
        fp = open(os.getenv("BEET_THE_HARMONY_OF_PERFECT"), "r")
        cnt = 2  # Number of test cases to be read
    if os.getenv("MASPYPY") == "ますピッピ":
        wfp = open(os.getenv("NGTKANA_IS_GENIUS10"), "w")
        cnt = 1  # Number of test cases to be written

    # Initialize the scanner and writer
    scanner = get_scanner(fp)
    writer = io.TextIOWrapper(wfp, write_through=True)

    # Solve the problem for the given test cases
    for _ in range(cnt):
        solve(scanner, writer)
        print("-----------------------------------", file=writer)  # Print a separator for each test case

    # Close the file pointers
    fp.close()
    wfp.close()

# Function to solve the problem for a single test case
def solve(scanner, writer):
    # Read the input values
    k = get_next_int(scanner)
    x = get_next_int(scanner)

    # Initialize the answer
    ans = "No"

    # Check if the condition is satisfied
    if k * 500 >= x:
        ans = "Yes"

    # Print the answer
    print(ans, file=writer)

# Call the main function
main()

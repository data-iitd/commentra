import sys

# Mathematical constants
PI = 3.141592653589793238462643383279502884197169399375105820974
ten5p1 = 100001
ten6p1 = 1000001
ten8p1 = 100000001
ten9p1 = 1000000001

# Function to read integers from input
def read_int():
    return int(sys.stdin.readline().strip())

# Function to write integers to output
def write_int(var):
    sys.stdout.write(f"{var}")

# Function to write a new line
def write_newline():
    sys.stdout.write("\n")

# Main function
def main():
    # Run local test with specified input file
    # Uncomment the following line to run with a specific file
    # sys.stdin = open("dataabc155A.txt", "r")

    # Read two integers from input
    a = read_int()
    b = read_int()

    # Output the smaller integer b times
    if a < b:
        for _ in range(b):
            write_int(a)  # Write 'a' b times
            write_newline()  # New line after output
    else:
        for _ in range(a):
            write_int(b)  # Write 'b' a times
            write_newline()  # New line after output

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>

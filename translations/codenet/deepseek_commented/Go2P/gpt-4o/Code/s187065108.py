import sys

# Function to read an integer from input
def scan_int():
    return int(scan_string())

# Function to read a single word from input
def scan_string():
    return next(input_iterator)

# Function to read a list of integers from input
def scan_ints(n):
    return [scan_int() for _ in range(n)]

# Initialize input iterator
input_iterator = iter(sys.stdin.read().split())

# Main function to execute the program
def main():
    # Read initial values for r, D, and x
    r = scan_int()
    D = scan_int()
    x = scan_int()
    
    # Loop to calculate and print the values of x for 10 iterations
    for _ in range(10):
        x = r * x - D
        print(x)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

import sys

# Function to read an array of integers from stdin and return it
def scan_array_int():
    # Read the input line from stdin
    input_line = sys.stdin.readline().strip()
    # Split the input line by space and convert each to integer
    return list(map(int, input_line.split()))

# Function to initialize variables and start the main logic
def main():
    # Read the array of integers from stdin
    arr = scan_array_int()
    # Initialize variables a and b with the first two elements of the array
    a, b = arr[0], arr[1]
    # Initialize variables tap and consent with default values
    tap, consent = 0, 1
    # Loop until consent is greater than or equal to b
    while consent < b:
        # Increment consent by the sum of a and consent minus one
        consent += a - 1
        # Increment tap by one for each iteration
        tap += 1
    # Print the result, i.e., the number of taps required
    print(tap)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

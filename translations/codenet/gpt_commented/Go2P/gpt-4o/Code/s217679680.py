import sys

def main():
    # Read an array of integers from standard input
    arr = scan_array_int()
    # Assign the first two elements of the array to variables a and b
    a, b = arr[0], arr[1]
    # Initialize the number of taps needed to 0
    tap = 0
    # Initialize the consent variable to 1 (the starting point)
    consent = 1
    
    # Loop until the consent value is less than b
    while consent < b:
        # Update consent by adding (a - 1) to it
        consent += a - 1
        # Increment the tap count
        tap += 1
    
    # Print the total number of taps needed
    print(tap)

# Function to scan an array of integers from standard input
def scan_array_int():
    # Read a line from standard input
    line = sys.stdin.readline().strip()
    # Split the input line into strings and convert each to an integer
    return list(map(int, line.split()))

if __name__ == "__main__":
    main()

# <END-OF-CODE>

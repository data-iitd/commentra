import sys
import math

# Function to read integers from input
def read_int():
    return int(sys.stdin.readline().strip())

# Main function
def main():
    # Reads three integers H, W, and N from the standard input.
    H, W, N = read_int(), read_int(), read_int()
    
    # Determines the maximum of H and W and assigns it to A.
    A = max(H, W)
    
    # Calculates the result by dividing N by A and rounding up.
    # This is done by adding N-1 to the division result and then performing integer division by A.
    print((N + A - 1) // A)

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>

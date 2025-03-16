import sys
import math

# Function to read the next integer from input
def next_int():
    return int(sys.stdin.readline().strip())

# Function to output the result
def out(result):
    print(result)

# Main function where the program execution starts
def main():
    N = next_int()  # Read the number of pairs
    T = [0] * N  # Initialize list for T
    A = [0] * N  # Initialize list for A
    
    # Read pairs of integers into T and A
    for i in range(N):
        T[i], A[i] = map(int, sys.stdin.readline().strip().split())
    
    t, a = T[0], A[0]  # Initialize t and a with the first pair
    
    # Iterate through the remaining pairs to compute the required values
    for i in range(1, N):
        r = max(math.ceil(t / T[i]), math.ceil(a / A[i]))  # Calculate the required multiplier
        t, a = T[i] * r, A[i] * r  # Update t and a based on the multiplier
    
    out(t + a)  # Output the final result

# Call the main function to execute the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>

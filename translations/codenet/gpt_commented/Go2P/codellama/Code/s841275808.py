
import sys

def main():
    # Create a new scanner to read input from standard input
    scanner = sys.stdin
    scanner.split()
    
    # Read the number of elements
    N = int(scanner.readline())
    # Initialize slices to hold the original values and a sorted copy
    X = [0] * N
    Y = [0] * N
    
    # Read N integers into slice X and copy them to slice Y
    for i in range(N):
        X[i] = int(scanner.readline())
        Y[i] = X[i]
    
    # Sort the slice Y to find the median values
    Y.sort()
    # Calculate the two middle values (medians) for even-sized arrays
    m1 = Y[N // 2 - 1] # First median
    m2 = Y[N // 2]     # Second median
    
    # For each element in X, print the appropriate median based on its value
    for i in range(N):
        if X[i] <= m1:
            print(m2) # If X[i] is less than or equal to m1, print m2
        else:
            print(m1) # Otherwise, print m1

# END-OF-CODE

import sys

def main():
    # Read the number of elements
    N = int(sys.stdin.readline())
    # Initialize slices to hold the original values and a sorted copy
    X = []
    Y = []
    # Read N integers into slice X and copy them to slice Y
    for i in range(N):
        X.append(int(sys.stdin.readline()))
        Y.append(X[i])
    # Sort the slice Y to find the median values
    Y.sort()
    # Calculate the two middle values (medians) for even-sized arrays
    m1 = Y[N / 2 - 1] # First median
    m2 = Y[N / 2]     # Second median
    # For each element in X, print the appropriate median based on its value
    for i in range(N):
        if X[i] <= m1:
            print(m2) # If X[i] is less than or equal to m1, print m2
        else:
            print(m1) # Otherwise, print m1

if __name__ == "__main__":
    main()

# 
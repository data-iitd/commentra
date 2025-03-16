import sys

def main():
    # Read the number of elements
    N = int(sys.stdin.readline().strip())
    
    # Initialize lists to hold the original values and a sorted copy
    X = []
    Y = []
    
    # Read N integers into list X and copy them to list Y
    for _ in range(N):
        value = int(sys.stdin.readline().strip())
        X.append(value)
        Y.append(value)
    
    # Sort the list Y to find the median values
    Y.sort()
    
    # Calculate the two middle values (medians) for even-sized arrays
    m1 = Y[N // 2 - 1]  # First median
    m2 = Y[N // 2]      # Second median
    
    # For each element in X, print the appropriate median based on its value
    for value in X:
        if value <= m1:
            print(m2)  # If value is less than or equal to m1, print m2
        else:
            print(m1)  # Otherwise, print m1

if __name__ == "__main__":
    main()

# <END-OF-CODE>

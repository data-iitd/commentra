# Import the necessary libraries
import sys

def main():
    N = int(sys.stdin.readline().strip())  # Read the number of elements N from standard input
    X = list(map(int, sys.stdin.readline().strip().split()))  # Read N elements into list X
    Y = X.copy()  # Copy elements from X to Y
    
    Y.sort()  # Sort the list Y in ascending order
    
    # Calculate the median of the sorted list Y
    y = Y[N // 2]  # The median for odd N, or the middle element for even N
    
    # Iterate through each element in list X and output the appropriate median value
    for i in range(N):
        if X[i] < y:
            print(y)  # If the element in X is less than the median, output the median
        else:
            print(y - 1)  # Otherwise, output the median minus one

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>

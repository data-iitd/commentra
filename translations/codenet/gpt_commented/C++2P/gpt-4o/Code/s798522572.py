# Import necessary libraries
import sys

def main():
    # Read the number of elements (N) and a threshold (T) from input
    N, T = map(int, sys.stdin.readline().split())
    
    # Initialize a list A to hold the input values
    A = list(map(int, sys.stdin.readline().split()))
    
    # Initialize a list B to hold the transformed values
    B = [0] * N
    
    # Initialize m with the first element of A
    m = A[0]
    
    # Calculate the first element of B based on the first element of A and update m
    B[1] = A[1] - m
    m = min(m, A[1])
    
    # Loop through the remaining elements of A to fill B and update m
    for i in range(2, N):
        # Fill B[i] with the difference between A[i] and the minimum value found so far (m)
        B[i] = A[i] - m
        
        # Update m to be the minimum of the current m and A[i]
        m = min(m, A[i])
    
    # Count and output the number of times the maximum element in B appears
    print(B.count(max(B)))

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>

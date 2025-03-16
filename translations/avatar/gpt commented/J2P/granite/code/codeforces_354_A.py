
import sys

def main():
    # Read input from the console
    N, L, R, QL, QR = map(int, input().split()) # Number of elements, left cost, right cost, left excess cost, right excess cost
    
    # Read weights and compute the prefix sum
    W = list(map(int, input().split())) # List to store weights
    sum = [0] * (N + 1) # Prefix sum array
    for n in range(N):
        sum[n + 1] = sum[n] + W[n] # Update prefix sum
    
    # Initialize a variable to track the minimum cost
    min = sys.maxsize # Start with the maximum possible value
    
    # Iterate over possible counts of elements assigned to the left side
    for firstR in range(N + 1):
        lCount = firstR # Count of elements on the left
        rCount = N - lCount # Count of elements on the right
        
        # Calculate the candidate cost based on current left and right counts
        cand = sum[lCount] * L + (sum[N] - sum[lCount]) * R # Calculate candidate cost
        
        # Calculate excess counts for left and right
        llCount = max(0, lCount - rCount - 1) # Excess left count
        rrCount = max(0, rCount - lCount - 1) # Excess right count
        
        # Add additional costs for excess elements
        cand += llCount * QL # Add cost for excess left elements
        cand += rrCount * QR # Add cost for excess right elements
        
        # Update the minimum cost found
        min = min(cand, min) # Keep track of the minimum cost
    
    # Output the minimum cost
    print(min) # Print the result

if __name__ == "__main__":
    main()


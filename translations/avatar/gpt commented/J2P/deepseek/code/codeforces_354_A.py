import sys

def main():
    # Read the number of elements (N) and the values for L, R, QL, QR
    N = int(input().split()[0])  # Number of elements
    L, R, QL, QR = map(int, input().split())  # Cost for left, right, and additional costs
    
    # Read weights and compute the prefix sum
    weights = list(map(int, input().split()))  # Array to store weights
    prefix_sum = [0] * (N + 1)
    for n in range(N):
        prefix_sum[n + 1] = prefix_sum[n] + weights[n]
    
    # Initialize a variable to track the minimum cost
    min_cost = sys.maxsize  # Start with the maximum possible value
    
    # Iterate over possible counts of elements assigned to the left side
    for firstR in range(N + 1):
        lCount = firstR  # Count of elements on the left
        rCount = N - lCount  # Count of elements on the right
        
        # Calculate the candidate cost based on current left and right counts
        cand = prefix_sum[lCount] * L + (prefix_sum[N] - prefix_sum[lCount]) * R
        
        # Calculate excess counts for left and right
        llCount = max(0, lCount - rCount - 1)  # Excess left count
        rrCount = max(0, rCount - lCount - 1)  # Excess right count
        
        # Add additional costs for excess elements
        cand += llCount * QL  # Add cost for excess left elements
        cand += rrCount * QR  # Add cost for excess right elements
        
        # Update the minimum cost found
        min_cost = min(cand, min_cost)  # Keep track of the minimum cost
    
    # Output the minimum cost
    print(min_cost)  # Print the result

if __name__ == "__main__":
    main()

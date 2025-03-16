def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    # Read the number of elements (N) and the values for L, R, QL, QR
    N = int(data[0])  # Number of elements
    L = int(data[1])  # Cost for left elements
    R = int(data[2])  # Cost for right elements
    QL = int(data[3])  # Additional cost for left excess
    QR = int(data[4])  # Additional cost for right excess
    
    # Initialize a list to hold the weights and a prefix sum list
    W = [0] * N  # List to store weights
    sum_prefix = [0] * (N + 1)  # Prefix sum list
    
    # Read weights and compute the prefix sum
    for n in range(N):
        W[n] = int(data[5 + n])  # Read weight for each element
        sum_prefix[n + 1] = sum_prefix[n] + W[n]  # Update prefix sum
    
    # Initialize a variable to track the minimum cost
    min_cost = float('inf')  # Start with the maximum possible value
    
    # Iterate over possible counts of elements assigned to the left side
    for firstR in range(N + 1):
        lCount = firstR  # Count of elements on the left
        rCount = N - lCount  # Count of elements on the right
        
        # Calculate the candidate cost based on current left and right counts
        cand = sum_prefix[lCount] * L + (sum_prefix[N] - sum_prefix[lCount]) * R
        
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

# <END-OF-CODE>

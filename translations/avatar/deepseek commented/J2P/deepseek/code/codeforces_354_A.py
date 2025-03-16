def main():
    # Reading the number of items and coefficients
    N = int(input())
    L = int(input())
    R = int(input())
    QL = int(input())
    QR = int(input())
    
    # Reading the weights of items
    W = list(map(int, input().split()))
    
    # Calculating cumulative sums of weights
    sum_weights = [0] * (N + 1)
    for n in range(N):
        sum_weights[n + 1] = sum_weights[n] + W[n]
    
    # Initializing the minimum cost to a very large value
    min_cost = float('inf')
    
    # Iterating over possible positions for the rightmost item
    for firstR in range(N + 1):
        lCount = firstR  # Number of items on the left
        rCount = N - lCount  # Number of items on the right
        
        # Calculating the cost for the current position of the rightmost item
        cand = sum_weights[lCount] * L + (sum_weights[N] - sum_weights[lCount]) * R
        
        # Calculating the additional costs for unbalanced counts
        llCount = max(0, lCount - rCount - 1)
        rrCount = max(0, rCount - lCount - 1)
        cand += llCount * QL
        cand += rrCount * QR
        
        # Updating the minimum cost found so far
        min_cost = min(cand, min_cost)
    
    # Printing the minimum cost
    print(min_cost)

# Calling the main function
main()

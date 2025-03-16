import sys

def main():
    # Read the number of elements (N) and the values for L, R, QL, QR
    N, L, R, QL, QR = map(int, sys.stdin.readline().split())
    
    # Initialize an array to hold the weights and a prefix sum array
    W = [0] * N
    sum = [0] * (N + 1)
    
    # Read weights and compute the prefix sum
    for n in range(N):
        W[n] = int(sys.stdin.readline())
        sum[n + 1] = sum[n] + W[n]
    
    # Initialize a variable to track the minimum cost
    min = sys.maxsize
    
    # Iterate over possible counts of elements assigned to the left side
    for firstR in range(N + 1):
        lCount = firstR
        rCount = N - lCount
        
        # Calculate the candidate cost based on current left and right counts
        cand = sum[lCount] * L + (sum[N] - sum[lCount]) * R
        
        # Calculate excess counts for left and right
        llCount = max(0, lCount - rCount - 1)
        rrCount = max(0, rCount - lCount - 1)
        
        # Add additional costs for excess elements
        cand += llCount * QL
        cand += rrCount * QR
        
        # Update the minimum cost found
        min = min(cand, min)
    
    # Output the minimum cost
    print(min)



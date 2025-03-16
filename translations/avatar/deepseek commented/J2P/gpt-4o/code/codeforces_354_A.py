# Importing the necessary module for input
import sys

def main():
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])  # Reading the number of items
    L = int(data[1])  # Reading the cost coefficient for items
    R = int(data[2])  # Reading the cost coefficient for items
    QL = int(data[3])  # Reading the cost coefficient for unbalanced left count
    QR = int(data[4])  # Reading the cost coefficient for unbalanced right count
    W = list(map(int, data[5:5 + N]))  # Array to store the weights of items
    sum_weights = [0] * (N + 1)  # Array to store cumulative sums of weights

    # Calculating cumulative sums
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

if __name__ == "__main__":
    main()

# <END-OF-CODE>

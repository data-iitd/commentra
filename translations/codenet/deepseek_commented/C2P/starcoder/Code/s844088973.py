# Read two integers, K and X, from the standard input
K, X = map(int, input().split())

# Loop from X-K+1 to X+K-1
for i in range(X - K + 1, X + K):
    # Print a space after each number except the last one
    if i < X + K - 1:
        print(i, end=' ')
    else:
        # Print a newline character to move to the next line
        print(i)


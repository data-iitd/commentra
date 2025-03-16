# <START-OF-CODE>

# Declare two integer variables K and X
K, X = 0, 0

# Read two integers from standard input: K and X
K, X = map(int, input().split())

# Loop from (X - K + 1) to (X + K - 1)
for i in range(X - K + 1, X + K):
    # Print the current value of i
    print(i, end = " ")

# Print a newline character after the loop completes
print()

# 
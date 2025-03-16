# Read two integers N and M from input
N, M = map(int, input().split())

# Calculate the number of ways to choose 2 items from N (combinations of N taken 2)
a = N * (N - 1) // 2

# Calculate the number of ways to choose 2 items from M (combinations of M taken 2)
b = M * (M - 1) // 2

# Output the total number of combinations from both N and M
print(a + b)

from itertools import accumulate

# Read input values: N (number of elements), X (a constant), and A (the list of integers)
N, X, *A = map(int, open(0).read().split())

# Calculate the cumulative sum of the list A
S = list(accumulate(A))

# Initialize the answer to a very large number (infinity)
ans = float("inf")

# Iterate through the cumulative sums with an index starting from 1
for k, s in enumerate(S, 1):
    # Calculate the expression E based on the current index k and the cumulative sums
    E = k * X + 2 * sum(S[j] for j in range(N - 2 * k - 1, -1, -k))
    
    # Update the answer with the minimum value found so far
    ans = min(ans, E)

# Print the final result, which includes the minimum value found, adjusted by N * X and 5 times the last cumulative sum
print(ans + N * X + 5 * S[-1])

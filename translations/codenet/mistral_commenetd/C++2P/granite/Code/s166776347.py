
# Python code
import sys

# Read input from standard input
N, K = map(int, input().split())
A = list(map(int, input().split()))

# Initialize answer for the first part
ans1 = 0

# Iterate through all elements in array A
for i in range(N):
    for j in range(N):
        if i >= j:
            continue
        if A[i] > A[j]:
            ans1 += 1

# Update answer modulo 1e9+7
ans1 %= 100000007

# Initialize an array to store the count of each unique element in array A
count = [0] * 2005

# Iterate through all elements in array A
for i in range(N):
    count[A[i] - 1] += 1

# Initialize answer for the second part
ans2 = 0

# Initialize the remaining number of elements to be paired
remain = N

# Iterate through all unique elements in array A
for i in range(2005):
    remain -= count[i]
    ans2 += count[i] * remain

# Update the answer for the second part modulo 1e9+7
ans2 %= 100000007

# Calculate (K*(K-1)) modulo 1e9+7
tmp = K * (K - 1)
tmp //= 2
tmp %= 100000007

# Multiply the temporary variable with the answer for the second part
tmp *= ans2
tmp %= 100000007

# Add the answer for the first part multiplied by K to the final answer
ans = ans1 * K
ans %= 100000007

# Add the temporary variable to the final answer
ans += tmp
ans %= 100000007

# Print the final answer
print(ans)


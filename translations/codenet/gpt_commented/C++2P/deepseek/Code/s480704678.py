# Read the number of elements
n = int(input())

# Initialize a list to store the input values and a list for prefix sums
a = list(map(int, input().split()))
acc = [0] * (n + 1)

# Compute prefix sums modulo MOD
for i in range(n):
    acc[i + 1] = acc[i] + a[i]
    acc[i + 1] %= 1000000007

# Initialize the answer variable
ans = 0

# Calculate the final answer using the prefix sums
for i in range(n):
    ans += a[i] % 1000000007 * (1000000007 + acc[n] - acc[i + 1]) % 1000000007
    ans %= 1000000007

# Output the final result
print(ans)

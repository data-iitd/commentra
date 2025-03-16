
# Read the number of elements
n = int(input())

# Initialize a list to store the input values and a list for prefix sums
a = [int(input()) for _ in range(n)]
acc = [0] * (n + 1)

# Compute prefix sums modulo MOD
for i in range(n):
    acc[i + 1] = (acc[i] + a[i]) % MOD

# Initialize the answer variable
ans = 0

# Calculate the final answer using the prefix sums
for i in range(n):
    ans += a[i] * (MOD + acc[n] - acc[i + 1]) % MOD
    ans %= MOD

# Output the final result
print(ans)

Translate the above Python code to Java and end with comment "
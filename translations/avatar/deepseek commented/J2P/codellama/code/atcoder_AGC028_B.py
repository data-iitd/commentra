
import sys

# Step 1: Read the input number n and the array elements
n = int(sys.stdin.readline())
a = list(map(int, sys.stdin.readline().split()))

# Step 2: Calculate the factorial of n modulo 10^9 + 7
mod = 1000000007
p = 1
for i in range(2, n + 1):
    p = (p * i) % mod

# Step 3: Calculate the inverse modulo for each number from 2 to n
q = [1] * n
for i in range(1, n):
    q[i] = (q[i - 1] + pow(i + 1, mod - 2, mod)) % mod

# Step 4: Calculate the answer using the given formula
ans = 0
for i in range(n):
    val = (q[i] + q[n - i - 1] - 1) % mod
    val = (val * a[i]) % mod
    val = (val * p) % mod
    ans = (ans + val) % mod

# Step 5: Print the final answer
print(ans)

# END-OF-CODE

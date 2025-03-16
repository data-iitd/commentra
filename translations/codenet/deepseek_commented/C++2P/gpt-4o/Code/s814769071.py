# Step 1: Import necessary libraries
MOD = 10**9 + 7

# Step 2: Read input values
n, k = map(int, input().split())

# Step 3: Calculate the maximum and minimum sums
mx = n * (n + 1) // 2 - (n - k) * (n - k + 1) // 2
mn = k * (k - 1) // 2

# Step 4: Initialize variables
res = 0

# Step 5: Loop through possible lengths
for i in range(k, n + 2):
    # Update res, mx, and mn in each iteration
    res += mx - mn + 1
    mx += n - i
    mn += i
    res %= MOD

# Step 6: Output the result
print(res)

# <END-OF-CODE>

# Read two integers from input, n and k
n, k = map(int, input().split())

# Check if k is divisible by n
# If it is, print the sum of n and k
# If not, print the difference between k and n
print(n + k if k % n == 0 else k - n)

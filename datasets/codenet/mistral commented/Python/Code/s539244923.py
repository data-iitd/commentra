
n, k = map(int, input().split())

# Define variables n and k using map() and input().split()

if k % n == 0:
# If k is divisible by n, print the sum of n and k
 print(n + k)
else:
# Otherwise, print the difference between k and n
 print(k - n)
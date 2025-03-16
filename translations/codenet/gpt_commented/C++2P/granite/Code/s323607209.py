
# Read input values for n and k
n, k = map(int, input().split())

# Check if k is even
if k % 2 == 0:
    # Initialize counters for specific conditions
    l = 0
    r = 0
    # Loop through numbers from 1 to n
    for i in range(1, n + 1):
        # Count how many numbers are exactly half of k (mod k)
        if i % k == k // 2:
            l += 1
        # Count how many numbers are multiples of k
        elif i % k == 0:
            r += 1
    # Calculate and print the result based on the counts
    # The result is the cube of l plus the cube of r
    print(l ** 3 + r ** 3)
else:
    # If k is odd, only count multiples of k
    r = 0
    for i in range(1, n + 1):
        # Count how many numbers are multiples of k
        if i % k == 0:
            r += 1
    # Print the result as the cube of r
    print(r ** 3)


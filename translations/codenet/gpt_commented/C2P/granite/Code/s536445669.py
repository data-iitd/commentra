
# Read two integers from user input
n, k = map(int, input().split())

# Check if n is divisible by k
if n % k == 0:
    # If n is divisible by k, print 0
    print(0)
else:
    # If n is not divisible by k, print 1
    print(1)

# 
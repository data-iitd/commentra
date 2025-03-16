
# Read two integers from the standard input using input
n, k = map(int, input().split())

# Check if 'n' is divisible by 'k'
if n % k == 0:
    # If it is, print '0' to the standard output
    print(0)
else:
    # If it's not, print '1' to the standard output
    print(1)

# 
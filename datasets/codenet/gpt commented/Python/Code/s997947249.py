# Read two integers N and K from user input
N, K = map(int, input().split())

# Check if N is divisible by K
if N % K == 0:
    # If N is divisible by K, print 0
    print(0)
else:
    # If N is not divisible by K, print 1
    print(1)

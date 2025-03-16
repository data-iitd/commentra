
N, K = map(int, input().split())
# Taking two inputs, N and K, and mapping them to integers

if N % K == 0:
    # Checking if N is divisible by K
    print(0)
    # If N is divisible by K, print 0
else:
    print(1)
    # If N is not divisible by K, print 1


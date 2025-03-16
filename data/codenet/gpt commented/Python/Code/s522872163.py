# Read two integers from input and assign them to X and A
X, A = list(map(int, input().split()))

# Check if X is less than A
if X < A:
    # If X is less than A, print 0
    print(0)
else:
    # If X is greater than or equal to A, print 10
    print(10)


n, k = map(int, input().split())
# Take two integers, `n` and `k`, from the input.

if k%2==1:
    # Check if `k` is odd.
    print((n//k)**3)
    # If `k` is odd, calculate the cube of the integer division of `n` by `k` and print the result.
else:
    # If `k` is even, calculate two values:
    print((n//k)**3 + ((n+k//2)//k)**3)
    # Calculate the cube of the integer division of `n` by `k` and the cube of the integer division of `n + k//2` by `k`,
    # then add them together and print the result.


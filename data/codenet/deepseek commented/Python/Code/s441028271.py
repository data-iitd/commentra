
(a, b, c, k) = list(map(int, input().split()))
# Taking four inputs from the user and storing them in variables `a`, `b`, `c`, and `k`.

if k % 2 == 0:
    # Checking if `k` is even.
    print(a-b)
    # If `k` is even, print the difference between `a` and `b`.
else:
    # Checking if `k` is odd.
    print(b-a)
    # If `k` is odd, print the difference between `b` and `a`.


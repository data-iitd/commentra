
from cmd import IDENTCHARS

# Take an integer input `n`
n = int(input())

# Initialize `l` and `r` to 1 and `n` respectively
l = 1
r = n

# The `while` loop runs as long as `l` is less than `r`
while (l < r):
    # Calculate the midpoint `mid`
    mid = l + (r - l) // 2
    # Calculate the triangular number `idxcnt` at `mid`
    idxcnt = mid * (mid + 1) / 2
    # If `idxcnt` is less than `n`, update `l` to `mid + 1`
    if (idxcnt < n):
        l = mid + 1
    # Otherwise, update `r` to `mid`
    else:
        r = mid

# Decrease `l` by 1 and calculate the triangular number `idxcnt` at `l`
l -= 1
idxcnt = l * (l + 1) / 2

# Print the difference between `n` and `idxcnt`
print(int(n - idxcnt))


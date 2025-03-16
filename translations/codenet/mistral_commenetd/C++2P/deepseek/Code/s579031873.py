import sys

# Read two integers from the standard input stream and assign them to "N" and "X" respectively.
N, X = map(int, sys.stdin.readline().split())

# Initialize an integer variable named "ans" to zero.
ans = 0
# Initialize an integer variable named "min" to a large value.
min_val = 1000000000

# Read N integers from the standard input stream and update "X" and "ans" accordingly.
for _ in range(N):
    tmp = int(sys.stdin.readline())
    X -= tmp
    ans += 1
    if tmp < min_val:
        min_val = tmp

# Divide "X" by the minimum value and add the quotient to "ans".
ans += X // min_val

# Output the value of "ans" to the standard output stream.
print(ans)

# End of the code.

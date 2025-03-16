
import sys
input = sys.stdin.readline

# Read two integers from standard input
a, b = map(int, input().split())

# Check if age `a` is 13 or older
if a >= 13:
    # Print the full price `b`
    print(b)
# Check if age `a` is between 6 and 12 (inclusive)
elif a >= 6:
    # Print half price of `b`
    print(int(b/2))
# If age `a` is less than 6
else:
    # Print 0
    print(0)


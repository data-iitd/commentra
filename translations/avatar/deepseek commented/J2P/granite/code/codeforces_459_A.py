
import sys

# Reading coordinates of two points
x1, y1, x2, y2 = map(int, input().split())

# Checking conditions to find the other two corners of a square or print -1
if x1 == x2:
    dif = abs(y1 - y2)
    print(f"{x1 + dif} {y1} {x1 + dif} {y2}")
elif y1 == y2:
    dif = abs(x1 - x2)
    print(f"{x1} {y1 + dif} {x2} {y2 + dif}")
elif abs(x1 - x2) == abs(y1 - y2):
    print(f"{x1} {y2} {x2} {y1}")
else:
    print(-1)

# Debugging method to print debug statements
def debug(*obj):
    print(*obj, file=sys.stderr)

# End of code

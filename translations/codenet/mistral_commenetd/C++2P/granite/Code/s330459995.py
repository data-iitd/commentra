
# Read input values from user
W, H, x, y, r = map(int, input().split())

# Check if point is inside the rectangle or not
if x-r<0 or x+r>W or y-r<0 or y+r>H:
    # If point is outside the rectangle
    print("No")
else:
    # If point is inside the rectangle
    print("Yes")

# End of code
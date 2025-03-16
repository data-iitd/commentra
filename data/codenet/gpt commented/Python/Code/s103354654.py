# Read input values for width (W), height (H), x-coordinate (x), y-coordinate (y), and radius (r)
W, H, x, y, r = map(int, input().split())

# Check if the circle's center (x, y) is within the horizontal bounds of the rectangle
if x >= r and (W - r) >= x:
    # Check if the circle's center (x, y) is within the vertical bounds of the rectangle
    if y >= r and (H - r) >= y:
        # If both conditions are satisfied, the circle fits within the rectangle
        print('Yes')
    else:
        # If the vertical condition is not satisfied, the circle does not fit
        print('No')
else:
    # If the horizontal condition is not satisfied, the circle does not fit
    print('No')

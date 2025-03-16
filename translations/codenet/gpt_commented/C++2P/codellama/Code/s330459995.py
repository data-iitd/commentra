# Declare variables for width (W), height (H), circle center coordinates (x, y), and radius (r)
W, H, x, y, r = 0, 0, 0, 0, 0

# Read input values for width, height, circle center coordinates, and radius
W, H, x, y, r = map(int, input().split())

# Check if the circle is out of bounds on any side
if x - r < 0 or x + r > W or y - r < 0 or y + r > H:
    # If the circle exceeds the boundaries, print "No"
    print("No")

# Check if the circle is completely within the bounds
elif x - r >= 0 and x + r <= W and y - r >= 0 and y + r <= H:
    # If the circle is completely within the boundaries, print "Yes"
    print("Yes")

# End of the program
print("
#######
# Code
#######

# Define variables and get their values from user input
W, H, x, y, r = map(int, input().split())

# Check if the given circle can fit inside the given rectangle
if x >= r and (W - r) >= x and y >= r and (H - r) >= y:
    # If the circle can fit inside the rectangle, further check if it's completely inside
    # If both conditions are true, print 'Yes'
    print('Yes')
else:
    # If the circle can't fit inside the rectangle or not completely inside, print 'No'
    print('No')

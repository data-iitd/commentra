# Read the height (H) and width (W) of the larger rectangle from input
H, W = map(int, input().split())

# Read the height (h) and width (w) of the smaller rectangle from input
h, w = map(int, input().split())

# Calculate the area of the larger rectangle and subtract the area occupied by the smaller rectangle
# The formula used is: Total area - (Area of smaller rectangle + Area of rectangles formed by smaller rectangle's dimensions)
ans = H * W - (h * W + w * H - h * w) 

# Output the result which is the area of the remaining space
print(ans)

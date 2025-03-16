# Take input for the dimensions of the grid
H, W = map(int, input().split())

# Take input for the dimensions of the area to be removed
h, w = map(int, input().split())

# Calculate the number of cells remaining after removing the specified area
ans = H * W - (h * W + w * H - h * w)

# Print the result
print(ans)

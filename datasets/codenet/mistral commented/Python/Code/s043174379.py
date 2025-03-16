
H, W = map(int, input().split())  # Read input values H and W
h, w = map(int, input().split())  # Read input values h and w

# Assign input values to variables h and w

ans = H * W - (h * W + w * H - h * w)  # Calculate the answer using the given formula
print(ans)  # Print the answer
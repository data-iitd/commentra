# Declare variables
W, H, x, y, r = map(int, input().split())

# Check if point is inside the rectangle or not
if x-r<0 or x+r>W or y-r<0 or y+r>H:
	# If point is outside the rectangle
	print("No")
elif x-r>=0 and x+r<=W and y-r>=0 and y+r<=H:
	# If point is inside the rectangle
	print("Yes")

# 
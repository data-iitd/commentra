# Declare variables to hold the input values for x and y
x = 0
y = 0

# Read two integers from standard input
x, y = map(int, input().split())

# Check if either x or y is equal to 2, and print "No" if true
# This is based on the problem's specific condition
if x == 2 or y == 2:
	print("No")
	return # Exit the function early if the condition is met

# Determine the group classification for both x and y
xg = "A" if x in [4, 6, 9, 11] else "B"
yg = "A" if y in [4, 6, 9, 11] else "B"

# Compare the group classifications of x and y
# Print "Yes" if they belong to the same group, otherwise print "No"
if xg == yg:
	print("Yes")
else:
	print("No")


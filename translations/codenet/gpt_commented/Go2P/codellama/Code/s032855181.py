
# group function determines the group classification based on the input number n.
# It returns "B" for specific values (4, 6, 9, 11) and "A" for all other values.
def group(n):
    if n == 4 or n == 6 or n == 9 or n == 11:
        return "B"
    else:
        return "A"

# Read two integers from standard input
x, y = map(int, input().split())

# Check if either x or y is equal to 2, and print "No" if true
# This is based on the problem's specific condition
if x == 2 or y == 2:
    print("No")
    exit() # Exit the function early if the condition is met

# Determine the group classification for both x and y
xg = group(x)
yg = group(y)

# Compare the group classifications of x and y
# Print "Yes" if they belong to the same group, otherwise print "No"
if xg == yg:
    print("Yes")
else:
    print("No")


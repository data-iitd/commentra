import sys

# Read the input from the console
h, w, n, sr, sc = map(int, sys.stdin.readline().split())
s = sys.stdin.readline().strip()
t = sys.stdin.readline().strip()

# Initialize the safe boundaries for vertical movement
usafe = 1 # Upper safe boundary
dsafe = h # Lower safe boundary

# Process the vertical moves in reverse order
for i in range(n - 1, -1, -1):
    # Update the safe boundaries based on the moves
    if s[i] == 'U':
        usafe += 1
    elif s[i] == 'D':
        dsafe -= 1

    # Check if the upper safe boundary exceeds the lower safe boundary
    if usafe > dsafe:
        print("NO")
        break

    # Adjust the safe boundaries based on the obstacles
    if i > 0:
        if t[i - 1] == 'U':
            dsafe = min(dsafe + 1, h)
        elif t[i - 1] == 'D':
            usafe = max(usafe - 1, 1)

# Initialize the safe boundaries for horizontal movement
lsafe = 1 # Left safe boundary
rsafe = w # Right safe boundary

# Process the horizontal moves in reverse order
for i in range(n - 1, -1, -1):
    # Update the safe boundaries based on the moves
    if s[i] == 'L':
        lsafe += 1
    elif s[i] == 'R':
        rsafe -= 1

    # Check if the left safe boundary exceeds the right safe boundary
    if lsafe > rsafe:
        print("NO")
        break

    # Adjust the safe boundaries based on the obstacles
    if i > 0:
        if t[i - 1] == 'L':
            rsafe = min(rsafe + 1, w)
        elif t[i - 1] == 'R':
            lsafe = max(lsafe - 1, 1)

# Check if the starting position is within the safe boundaries and not marked as unsafe
if sr >= usafe and sr <= dsafe and sc >= lsafe and sc <= rsafe:
    print("YES")
else:
    print("NO")

# 
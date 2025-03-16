

import math

# Read input values for A, B, H, and M
A = int(input())
B = int(input())
H = int(input())
M = int(input())

# Calculate the angles for the minute and hour hands in degrees
mkaku = M * 6  # Minute hand angle
hkaku = H * 30 + M / 2  # Hour hand angle

# Calculate the difference between the two angles
kaku = abs(mkaku - hkaku)

# Convert the angle difference to radians
dkaku = math.radians(kaku)

# Calculate the cosine of the angle in radians
AA2 = A * A
BB2 = B * B
CC = AA2 + BB2
DD = 2 * math.cos(dkaku) * A * B
ans2 = CC - DD

# Calculate the distance using the cosine rule
ans = math.sqrt(ans2)

# Print the final answer
print(ans)

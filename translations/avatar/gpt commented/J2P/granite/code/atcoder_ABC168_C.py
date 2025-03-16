
import math

# Read integer inputs A, B, H, and M from the user
A = int(input())
B = int(input())
H = int(input())
M = int(input())

# Calculate the angle of the minute hand in degrees
mkaku = M * 6

# Calculate the angle of the hour hand in degrees
hkaku = H * 30 + M / 2

# Calculate the difference in angles between the two hands
kaku = abs(mkaku - hkaku)

# Convert the angle difference from degrees to radians
dkaku = math.radians(kaku)

# Calculate the squares of A and B
AA2 = A * A
BB2 = B * B

# Calculate the sum of squares of A and B
CC = AA2 + BB2

# Calculate the cosine of the angle difference and adjust for the formula
DD = math.cos(dkaku) * 2 * A * B

# Calculate the final result using the derived formula
ans2 = CC - DD

# Calculate the square root of the result
ans = math.sqrt(ans2)

# Output the final result
print(ans)


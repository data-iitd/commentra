
import math
import cmath

# Read input values for A, B, H, and M
A = int(input())
B = int(input())
H = int(input())
M = int(input())

# Initialize BigDecimal variables for precision
AA = A
BB = B
HH = H
MM = M

# Calculate the angles for the minute and hour hands in degrees
mkaku = MM * 6
hkaku = HH * 30 + M / 2

# Calculate the difference between the two angles
kaku = mkaku - hkaku

# Convert the angle difference to radians
dkaku = math.fabs(math.radians(kaku))

# Calculate the cosine of the angle in radians
AA2 = AA * AA
BB2 = BB * BB
CC = AA2 + BB2
DD = 2 * AA * BB * math.cos(dkaku)

# Calculate the distance using the cosine rule
ans2 = CC - DD

# Convert the result to double for square root calculation
dans2 = ans2

# Calculate the square root of the distance
ans = math.sqrt(dans2)

# Print the final answer
print(ans)


import math 
import cmath 

# Read integer inputs A, B, H, and M from the user
A = int(input()) 
B = int(input()) 
H = int(input()) 
M = int(input()) 

# Convert integer inputs to float for precise calculations
AA = float(A) 
BB = float(B) 
HH = float(H) 
MM = float(M) 

# Declare variables for calculations
ans2 = 0 
kaku = 0 
mkaku = 0 
hkaku = 0 
AA2 = 0 
BB2 = 0 
CC = 0 
DD = 0 
dkaku = 0 
dans2 = 0 

# Calculate the angle of the minute hand in degrees
mkaku = MM * 6 

# Calculate the angle of the hour hand in degrees
hkaku = HH * 30 + (M / 2) 

# Calculate the difference in angles between the two hands
kaku = mkaku - hkaku 

# Convert the angle difference from degrees to radians
dkaku = math.fabs(math.radians(kaku)) 

# Calculate the squares of A and B
AA2 = AA ** 2 
BB2 = BB ** 2 

# Calculate the sum of squares of A and B
CC = AA2 + BB2 

# Calculate the cosine of the angle difference and adjust for the formula
DD = 2 * AA * BB * math.cos(dkaku) 

# Calculate the final result using the derived formula
ans2 = CC - DD 

# Convert the result to float for square root calculation
dans2 = float(ans2) 

# Calculate the square root of the result
ans = math.sqrt(dans2) 

# Output the final result
print(ans) 


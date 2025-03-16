
import math
import decimal

A = int(input())
B = int(input())
H = int(input())
M = int(input())

# Creating decimal objects for the input values
AA = decimal.Decimal(A)
BB = decimal.Decimal(B)
HH = decimal.Decimal(H)
MM = decimal.Decimal(M)

# Declaring and initializing variables for intermediate calculations
ans2
kaku
mkaku
hkaku
AA2
BB2
CC
DD
dkaku
dans2

# Calculating mkaku (M multiplied by 6) and hkaku (H multiplied by 30 and added half of M)
mkaku = MM * 6
hkaku = HH * 30 + MM / 2

# Calculating kaku (difference between mkaku and hkaku)
kaku = mkaku - hkaku

# Calculating the absolute value of kaku in radians
dkaku = abs(math.radians(kaku))

# Calculating the squared values of A and B
AA2 = AA ** 2
BB2 = BB ** 2

# Calculating CC (sum of squares of A and B) and DD (cosine of kaku multiplied by A and B)
CC = AA2 + BB2
DD = math.cos(dkaku) * AA * BB

# Calculating the answer (square root of the difference between CC and DD)
ans2 = CC - DD
dans2 = float(ans2)
ans = math.sqrt(dans2)

# Printing the answer
print(ans)


import math
import decimal

A = int(input())
B = int(input())
H = int(input())
M = int(input())

AA = decimal.Decimal(A)
BB = decimal.Decimal(B)
HH = decimal.Decimal(H)
MM = decimal.Decimal(M)

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
ans = 0

mkaku = MM * 6
hkaku = HH * 30 + MM / 2
kaku = mkaku - hkaku
dkaku = abs(math.radians(kaku))
AA2 = AA * AA
BB2 = BB * BB
CC = AA2 + BB2
DD = 2 * math.cos(dkaku) * AA * BB
ans2 = CC - DD
dans2 = float(ans2)
ans = math.sqrt(dans2)

print(ans)


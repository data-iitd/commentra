import math
import cmath
import decimal

def main():
    A = int(input())
    B = int(input())
    H = int(input())
    M = int(input())
    AA = decimal.Decimal(A)
    BB = decimal.Decimal(B)
    HH = decimal.Decimal(H)
    MM = decimal.Decimal(M)
    mkaku = MM * 6
    hkaku = HH * 30 + M / 2
    kaku = mkaku - hkaku
    dkaku = math.radians(abs(kaku))
    AA2 = AA ** 2
    BB2 = BB ** 2
    CC = AA2 + BB2
    DD = 2 * math.cos(dkaku) * AA * BB
    ans2 = CC - DD
    ans = math.sqrt(ans2)
    print(ans)

if __name__ == "__main__":
    main()


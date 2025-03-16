import math
import cmath

def main():
    # Reading the input values
    A = int(input())
    B = int(input())
    H = int(input())
    M = int(input())

    # Creating BigDecimal objects for the input values
    AA = A
    BB = B
    HH = H
    MM = M

    # Declaring and initializing variables for intermediate calculations
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

    # Calculating mkaku (M multiplied by 6) and hkaku (H multiplied by 30 and added half of M)
    mkaku = MM * 6
    hkaku = HH * 30 + MM / 2

    # Calculating kaku (difference between mkaku and hkaku)
    kaku = mkaku - hkaku

    # Calculating the absolute value of kaku in radians
    dkaku = abs(math.radians(kaku))

    # Calculating the squared values of A and B
    AA2 = AA * AA
    BB2 = BB * BB

    # Calculating CC (sum of squares of A and B) and DD (cosine of kaku multiplied by A and B)
    CC = AA2 + BB2
    DD = cmath.cos(dkaku) * AA * BB

    # Calculating the answer (square root of the difference between CC and DD)
    ans2 = CC - DD
    dans2 = ans2.real
    ans = math.sqrt(dans2)

    # Printing the answer
    print(ans)



import math

def main():
    # Reading the input values
    A = int(input())
    B = int(input())
    H = int(input())
    M = int(input())

    # Calculating mkaku (M multiplied by 6) and hkaku (H multiplied by 30 and added half of M)
    mkaku = M * 6
    hkaku = H * 30 + M / 2

    # Calculating kaku (difference between mkaku and hkaku)
    kaku = abs(mkaku - hkaku)

    # Calculating the absolute value of kaku in radians
    dkaku = math.radians(kaku)

    # Calculating the squared values of A and B
    AA2 = A ** 2
    BB2 = B ** 2

    # Calculating CC (sum of squares of A and B) and DD (cosine of kaku multiplied by A and B)
    CC = AA2 + BB2
    DD = math.cos(dkaku) * A * B

    # Calculating the answer (square root of the difference between CC and DD)
    ans2 = CC - DD
    ans = math.sqrt(ans2)

    # Printing the answer
    print(ans)

if __name__ == "__main__":
    main()

import math  # Importing the math module for mathematical functions

def main():
    # Reading the integer values A, B, H, M from the console
    A = int(input())
    B = int(input())
    H = int(input())
    M = int(input())

    # Calculating mkaku (M multiplied by 6) and hkaku (H multiplied by 30 and added half of M)
    mkaku = M * 6
    hkaku = H * 30 + M / 2

    # Calculating kaku (difference between mkaku and hkaku)
    kaku = mkaku - hkaku

    # Calculating the absolute value of kaku in radians
    dkaku = abs(math.radians(kaku))

    # Calculating the squared values of A and B
    AA2 = A * A
    BB2 = B * B

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

# <END-OF-CODE>

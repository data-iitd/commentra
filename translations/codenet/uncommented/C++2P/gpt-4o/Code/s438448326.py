def main():
    A, B, C, D, E, F = map(int, input().split())

    m1 = 0
    m2 = 0
    maxD = 0.0

    i = 0
    while 100 * A * i <= F:
        mA = 100 * A * i
        j = 0
        while mA + 100 * B * j <= F:
            mB = 100 * B * j
            k = 0
            while mA + mB + C * k <= F:
                mC = C * k
                l = 0
                while mA + mB + mC + D * l <= F:
                    mD = D * l
                    if (mA + mB) * E / 100 < mD + mC:
                        break
                    d = (mD + mC) / (mA + mB + mC + mD)
                    if d > maxD:
                        m1 = mA + mB + mC + mD
                        m2 = mC + mD
                        maxD = d
                    l += 1
                k += 1
            j += 1
        i += 1

    if m1 == 0:
        m1 = 100 * A

    print(m1, m2)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

def main():
    # Step 1: Reading Input
    A, B, C, D, E, F = map(int, input().split())

    # Step 2: Initializing Variables
    m1 = 0
    m2 = 0
    maxD = 0.0

    # Step 3: Nested Loops to Iterate Over Possible Combinations
    for i in range(F // (100 * A) + 1):
        mA = 100 * A * i
        for j in range(F // (100 * B) + 1):
            mB = 100 * B * j
            for k in range(F // C + 1):
                mC = C * k
                for l in range(F // D + 1):
                    mD = D * l
                    # Step 4: Calculating Density and Updating Results
                    if (mA + mB) * E / 100 < mD + mC:
                        break
                    d = (mD + mC) / (mA + mB + mC + mD)
                    if d > maxD:
                        m1 = mA + mB + mC + mD
                        m2 = mC + mD
                        maxD = d

    # Step 5: Handling Edge Cases
    if m1 == 0:
        m1 = 100 * A

    # Step 6: Output the Results
    print(m1, m2)


main()

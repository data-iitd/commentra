def main():
    # Declare variables to hold input values
    A, B, C, D, E, F = map(int, input().split())

    # Initialize variables to track the maximum values and the corresponding amounts
    m1, m2 = 0, 0
    maxD = 0.0

    # Iterate over possible values of A (scaled by 100)
    for i in range(F // (100 * A) + 1):
        mA = 100 * A * i

        # Iterate over possible values of B (scaled by 100)
        for j in range(F // (100 * B) + 1):
            mB = 100 * B * j

            # Iterate over possible values of C
            for k in range(F // C + 1):
                mC = C * k

                # Iterate over possible values of D
                for l in range(F // D + 1):
                    mD = D * l

                    # Check if the condition for the ratio is satisfied
                    if (mA + mB) * E < mD + mC:
                        break

                    # Calculate the current ratio of (mD + mC) to the total amount
                    d = (mD + mC) / (mA + mB + mC + mD)

                    # Update maximum values if the current ratio is greater
                    if d > maxD:
                        m1 = mA + mB + mC + mD
                        m2 = mC + mD
                        maxD = d

    # If no valid combination was found, set m1 to the minimum amount for A
    if m1 == 0:
        m1 = 100 * A

    # Output the results
    print(m1, m2)


main()

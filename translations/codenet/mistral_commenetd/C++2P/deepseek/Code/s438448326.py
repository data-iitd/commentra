import sys

# Main function
def main():
    # Read input values
    A, B, C, D, E, F = map(int, sys.stdin.readline().split())

    # Initialize variables for storing maximum sum and its components
    m1 = 0
    m2 = 0
    maxD = 0.0

    # Loop through all possible combinations of mA, mB, mC, mD that satisfy the condition F >= mA + mB + mC + mD
    for i in range(F // (100 * A) + 1):
        # Calculate current value of mA
        mA = 100 * A * i

        # Loop through all possible combinations of mB, mC, mD that satisfy the condition mA + 100*B*j <= F
        for j in range(F // (100 * B) + 1):
            # Calculate current value of mB
            mB = 100 * B * j

            # Check if the current combination satisfies the condition mA + mB <= F
            if mA + mB > F:
                continue

            # Loop through all possible combinations of mC, mD that satisfy the condition mA + mB + C*k <= F
            for k in range(F // C + 1):
                # Calculate current value of mC
                mC = C * k

                # Check if the current combination satisfies the condition mA + mB + mC <= F
                if mA + mB + mC > F:
                    continue

                # Loop through all possible combinations of mD that satisfy the condition mA + mB + mC + D*l <= F
                for l in range(F // D + 1):
                    # Calculate current value of mD
                    mD = D * l

                    # Check if the current combination satisfies the condition mA + mB + mC + mD <= F
                    if mA + mB + mC + mD > F:
                        continue

                    # Check if the current combination satisfies the condition (mA + mB)*E / 100 < mD + mC
                    if (mA + mB) * E / 100 < mD + mC:
                        continue

                    # Calculate the ratio d = (mD + mC) / (mA + mB + mC + mD)
                    d = (mD + mC) / (mA + mB + mC + mD)

                    # If the current ratio is greater than the maximum ratio found so far, update the maximum ratio and the corresponding values of m1 and m2
                    if d > maxD:
                        m1 = mA + mB + mC + mD
                        m2 = mC + mD
                        maxD = d

    # If no combination was found that satisfies the conditions, set m1 to the value of 100*A and print the result as 0 0
    if m1 == 0:
        m1 = 100 * A

    # Print the result
    print(m1, m2)

# Call the main function
if __name__ == "__main__":
    main()

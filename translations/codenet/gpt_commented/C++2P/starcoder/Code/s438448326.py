# Declare variables to hold input values
A, B, C, D, E, F = map(int, input().split())

# Initialize variables to track the maximum values and the corresponding amounts
m1 = 0
m2 = 0
maxD = 0.0

# Iterate over possible values of A (scaled by 100)
for i in range(F // (100 * A) + 1):
    mA = 100 * A * i # Calculate the total amount for A

    # Iterate over possible values of B (scaled by 100)
    for j in range(F // (mA + 100 * B) + 1):
        mB = 100 * B * j # Calculate the total amount for B

        # Iterate over possible values of C
        for k in range(F // (mA + mB + C) + 1):
            mC = C * k # Calculate the total amount for C

            # Iterate over possible values of D
            for l in range(F // (mA + mB + mC + D) + 1):
                mD = D * l # Calculate the total amount for D

                # Check if the condition for the ratio is satisfied
                if ((mA + mB) * E / 100 < mD + mC):
                    break # Exit the loop if the condition is not met

                # Calculate the current ratio of (mD + mC) to the total amount
                d = (mD + mC) / (mA + mB + mC + mD)

                # Update maximum values if the current ratio is greater
                if (d > maxD):
                    m1 = mA + mB + mC + mD # Update total amount
                    m2 = mC + mD # Update amount of C and D
                    maxD = d # Update maximum ratio

# If no valid combination was found, set m1 to the minimum amount for A
if (m1 == 0):
    m1 = 100 * A

# Output the results
print(m1, m2)
# 
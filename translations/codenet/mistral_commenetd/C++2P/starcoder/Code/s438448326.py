
# Initialize variables
A, B, C, D, E, F = map(int, input().split())

# Initialize variables for storing maximum sum and its components
m1 = 0
m2 = 0
maxD = 0.0

# Loop through all possible combinations of mA, mB, mC, mD that satisfy the condition F >= mA + mB + mC + mD
for i in range(F // (100*A) + 1):
	# Calculate current value of mA
	mA = 100 * A*i

	# Loop through all possible combinations of mB, mC, mD that satisfy the condition mA + 100*B*j <= F
	for j in range(F // (mA + 100*B) + 1):
		# Calculate current value of mB
		mB = 100 * B*j

		# Loop through all possible combinations of mC, mD that satisfy the condition mA + mB + C*k <= F
		for k in range(F // (mA + mB + C) + 1):
			# Calculate current value of mC
			mC = C*k

			# Loop through all possible combinations of mD that satisfy the condition mA + mB + mC + D*l <= F
			for l in range(F // (mA + mB + mC + D) + 1):
				# Calculate current value of mD
				mD = D*l

				# Check if the current combination satisfies the condition (mA + mB)*E / 100 < mD + mC
				if ((mA + mB)*E / 100 < mD + mC):
					# If so, break out of the inner loop and move on to the next combination of mA, mB, mC, mD
					break

				# Calculate the ratio d = (mD + mC) / (mA + mB + mC + mD)
				d = (mD + mC) / (mA + mB + mC + mD)

				# If the current ratio is greater than the maximum ratio found so far, update the maximum ratio and the corresponding values of m1 and m2
				if (d > maxD):
					m1 = mA + mB + mC + mD
					m2 = mC + mD
					maxD = d

			# If the current combination satisfies the condition (mA + mB)*E / 100 < mD + mC, break out of the inner loop and move on to the next combination of mA, mB, mC, mD
			if ((mA + mB)*E / 100 < mD + mC):
				break

		# If the current combination satisfies the condition (mA + mB)*E / 100 < mD + mC, break out of the inner loop and move on to the next combination of mA, mB, mC, mD
		if ((mA + mB)*E / 100 < mD + mC):
			break

	# If the current combination satisfies the condition (mA + mB)*E / 100 < mD + mC, break out of the inner loop and move on to the next combination of mA, mB, mC, mD
	if ((mA + mB)*E / 100 < mD + mC):
		break

# If no combination was found that satisfies the conditions, set m1 to the value of 100*A and print the result as 0 0
if (m1 == 0):
	m1 = 100 * A

# Print the result
print(m1, m2)

# 
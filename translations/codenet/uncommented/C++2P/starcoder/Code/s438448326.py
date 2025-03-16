
A, B, C, D, E, F = map(int, raw_input().split())

m1 = 0
m2 = 0
maxD = 0.0
for i in range(F // (100*A) + 1):
	mA = 100 * A*i
	for j in range(F // (100*B) + 1):
		mB = 100 * B*j
		for k in range(F // (C) + 1):
			mC = C*k
			for l in range(F // (D) + 1):
				mD = D*l
				if ((mA + mB)*E / 100 < mD + mC):
					break
				d = (float)(mD + mC) / (float)(mA + mB + mC + mD)
				if (d > maxD):
					m1 = mA + mB + mC + mD
					m2 = mC + mD
					maxD = d

if (m1 == 0):
	m1 = 100 * A

print m1, m2


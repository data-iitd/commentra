package main

import (
	"fmt"
)

func main() {
	// Step 1: Reading Input
	var A, B, C, D, E, F int
	fmt.Scan(&A, &B, &C, &D, &E, &F)

	// Step 2: Initializing Variables
	m1, m2 := 0, 0
	maxD := 0.0

	// Step 3: Nested Loops to Iterate Over Possible Combinations
	for i := 0; 100*A*i <= F; i++ {
		mA := 100 * A * i
		for j := 0; mA+100*B*j <= F; j++ {
			mB := 100 * B * j
			for k := 0; mA+mB+C*k <= F; k++ {
				mC := C * k
				for l := 0; mA+mB+mC+D*l <= F; l++ {
					mD := D * l
					// Step 4: Calculating Density and Updating Results
					if (mA + mB)*E/100 < mD+mC {
						break
					}
					d := (float64)(mD + mC) / (float64)(mA + mB + mC + mD)
					if d > maxD {
						m1 = mA + mB + mC + mD
						m2 = mC + mD
						maxD = d
					}
				}
			}
		}
	}

	// Step 5: Handling Edge Cases
	if m1 == 0 {
		m1 = 100 * A
	}

	// Step 6: Output the Results
	fmt.Println(m1, m2)
}


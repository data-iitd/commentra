

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Initialize variables
	A, B, C, D, E, F := 0, 0, 0, 0, 0, 0, 0
	// Read input values from the standard input
	reader := bufio.NewReader(os.Stdin)
	for i := 0; i < 7; i++ {
		input, _, err := reader.ReadLine()
		if err!= nil {
			fmt.Println(err)
			return
		}
		value, err := strconv.Atoi(string(input))
		if err!= nil {
			fmt.Println(err)
			return
		}
		switch i {
		case 0:
			A = value
		case 1:
			B = value
		case 2:
			C = value
		case 3:
			D = value
		case 4:
			E = value
		case 5:
			F = value
		}
	}

	// Initialize variables for storing maximum sum and its components
	m1 := 0
	m2 := 0
	maxD := 0.0

	// Loop through all possible combinations of mA, mB, mC, mD that satisfy the condition F >= mA + mB + mC + mD
	for i := 0; 100*A*i <= F; i++ {
		// Calculate current value of mA
		mA := 100 * A * i
		// Loop through all possible combinations of mB, mC, mD that satisfy the condition mA + 100*B*j <= F
		for j := 0; mA+100*B*j <= F; j++ {
			// Calculate current value of mB
			mB := 100 * B * j
			// Loop through all possible combinations of mC, mD that satisfy the condition mA + mB + C*k <= F
			for k := 0; mA+mB+C*k <= F; k++ {
				// Calculate current value of mC
				mC := C * k
				// Loop through all possible combinations of mD that satisfy the condition mA + mB + mC + D*l <= F
				for l := 0; mA+mB+mC+D*l <= F; l++ {
					// Calculate current value of mD
					mD := D * l
					// Check if the current combination satisfies the condition (mA + mB)*E / 100 < mD + mC
					if (mA+mB)*E/100 < mD+mC {
						// If so, break out of the inner loop and move on to the next combination of mA, mB, mC, mD
						break
					}
					// Calculate the ratio d = (mD + mC) / (mA + mB + mC + mD)
					d := float64(mD+mC) / float64(mA+mB+mC+mD)
					// If the current ratio is greater than the maximum ratio found so far, update the maximum ratio and the corresponding values of m1 and m2
					if d > maxD {
						m1 = mA + mB + mC + mD
						m2 = mC + mD
						maxD = d
					}
				}
			}
		}
	}

	// If no combination was found that satisfies the conditions, set m1 to the value of 100*A and print the result as 0 0
	if m1 == 0 {
		m1 = 100 * A
	}

	// Print the result
	fmt.Println(m1, m2)
}


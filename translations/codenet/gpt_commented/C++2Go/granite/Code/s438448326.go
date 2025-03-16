
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Declare variables to hold input values
	var A, B, C, D, E, F int

	// Read input values from the user
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < 7; i++ {
		scanner.Scan()
		num, _ := strconv.Atoi(scanner.Text())
		switch i {
		case 0:
			A = num
		case 1:
			B = num
		case 2:
			C = num
		case 3:
			D = num
		case 4:
			E = num
		case 5:
			F = num
		}
	}

	// Initialize variables to track the maximum values and the corresponding amounts
	m1 := 0
	m2 := 0
	maxD := 0.0

	// Iterate over possible values of A (scaled by 100)
	for i := 0; 100*A*i <= F; i++ {
		mA := 100 * A * i // Calculate the total amount for A

		// Iterate over possible values of B (scaled by 100)
		for j := 0; mA+100*B*j <= F; j++ {
			mB := 100 * B * j // Calculate the total amount for B

			// Iterate over possible values of C
			for k := 0; mA+mB+C*k <= F; k++ {
				mC := C * k // Calculate the total amount for C

				// Iterate over possible values of D
				for l := 0; mA+mB+mC+D*l <= F; l++ {
					mD := D * l // Calculate the total amount for D

					// Check if the condition for the ratio is satisfied
					if (mA+mB)*E/100 < mD+mC {
						break // Exit the loop if the condition is not met
					}

					// Calculate the current ratio of (mD + mC) to the total amount
					d := float64(mD+mC) / float64(mA+mB+mC+mD)

					// Update maximum values if the current ratio is greater
					if d > maxD {
						m1 = mA + mB + mC + mD // Update total amount
						m2 = mC + mD // Update amount of C and D
						maxD = d // Update maximum ratio
					}
				}
			}
		}
	}

	// If no valid combination was found, set m1 to the minimum amount for A
	if m1 == 0 {
		m1 = 100 * A
	}

	// Output the results
	fmt.Println(m1, m2)
}


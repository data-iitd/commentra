package main

import (
	"fmt"
)

func main() {
	var a, b, c, d, e, f int
	var x, y float64

	// Reading the input values
	// The code uses a for loop to read six integers from the standard input until the end of the input is reached.
	for {
		_, err := fmt.Scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f)
		if err != nil {
			break
		}

		// Calculating the values of x and y
		// The code calculates the values of x and y using the formula derived from the given equations.
		y = float64(c*d-f*a) / float64(b*d-e*a)
		x = float64(c*e-f*b) / float64(a*e-d*b)

		// Adjusting the values of x and y if they are very close to zero
		// The code checks if the values of x and y are very close to zero and adjusts them to exactly zero if they are.
		if y <= 0 && y > -0.0005 {
			y = 0
		}
		if x <= 0 && x > -0.0005 {
			x = 0
		}

		// Printing the results
		// The code prints the calculated values of x and y with three decimal places.
		fmt.Printf("%.3f %.3f\n", x, y)
	}
}

// <END-OF-CODE>

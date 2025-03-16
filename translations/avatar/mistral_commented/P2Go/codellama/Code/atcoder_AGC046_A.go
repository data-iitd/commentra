
package main

import (
	"fmt"
	"math"
)

func main() {
	// Ask the user for an integer input and assign it to the variable x
	var x int
	fmt.Scan(&x)

	// Calculate the greatest common divisor (gcd) of 360 and the user input x
	gcd_value := math.GCD(360, x)

	// Print the result of the division of 360 by the gcd
	fmt.Println(360 / gcd_value)
}


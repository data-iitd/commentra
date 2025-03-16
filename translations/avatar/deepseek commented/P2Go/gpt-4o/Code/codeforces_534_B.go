package main

import (
	"fmt"
)

func main() {
	var v1, v2 int
	fmt.Scan(&v1, &v2) // Taking two inputs from the user
	var t, d int
	fmt.Scan(&t) // Taking time input
	fmt.Scan(&d) // Taking distance input

	// Initializing variables
	a := 1
	v := v1
	distance := 0

	// Entering a loop that runs `t` times
	for i := 0; i < t; i++ {
		// Checking if the current speed `v` minus `v2` is greater than `(t - i - 1) * d`
		if v-v2 > (t-i-1)*d {
			a *= -1
			v = (t-i-1)*d + v2
		}
		// Adding the current speed `v` to `distance`
		distance += v
		// Updating the speed by adding `a * d` to it
		v += a * d
	}

	// Printing the total `distance`
	fmt.Println(distance)
}

// <END-OF-CODE>

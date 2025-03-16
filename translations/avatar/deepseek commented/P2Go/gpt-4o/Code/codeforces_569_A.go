package main

import (
	"fmt"
)

func main() {
	var t, s, q int
	// Taking three integer inputs and assigning them to variables t, s, and q
	fmt.Scan(&t, &s, &q)

	ans := 0
	// Initializing the variable ans to 0

	for s < t {
		// Starting a for loop that continues as long as s is less than t
		s *= q
		// Multiplying s by q
		ans++
		// Incrementing ans by 1
	}

	fmt.Println(ans)
	// Printing the final value of ans after the loop completes
}

// <END-OF-CODE>

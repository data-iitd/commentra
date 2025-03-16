package main

import (
	"fmt"
)

func main() {
	var candeleIntere, b int
	// Taking two integer inputs and assigning them to candeleIntere and b.
	fmt.Scan(&candeleIntere, &b)

	// Initializing the sum variable s and the remainder variable restoSciolte to 0.
	s := 0
	restoSciolte := 0

	// Starting a while loop that continues as long as candeleIntere is greater than 0 or restoSciolte is greater than or equal to b.
	for candeleIntere > 0 || restoSciolte >= b {
		// Updating candeleIntere by adding the integer division of restoSciolte by b.
		candeleIntere += restoSciolte / b

		// Updating restoSciolte to be the remainder of the division of restoSciolte by b.
		restoSciolte %= b

		// Adding candeleIntere to s.
		s += candeleIntere

		// Updating restoSciolte by adding the remainder of candeleIntere divided by b.
		restoSciolte += candeleIntere % b

		// Updating candeleIntere by performing integer division of candeleIntere by b.
		candeleIntere /= b
	}

	// Printing the value of s after the loop completes.
	fmt.Println(s)
}

// <END-OF-CODE>

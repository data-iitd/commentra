package main

import (
	"fmt"
)

func main() {
	var N, A, B int
	fmt.Scan(&N, &A, &B) // Reading N, A, and B

	mod := 1000000007 // Modulo value
	ans := 0          // Initializing the result variable

	// Calculating the number of complete cycles of A + B within N
	rep := N / (A + B)

	// Updating the result with the number of complete cycles multiplied by A
	ans += rep * A

	// Calculating the remaining days after the complete cycles
	res := N - rep*(A+B)

	// Updating the result with the minimum of the remaining days and A
	if res < A {
		ans += res
	} else {
		ans += A
	}

	// Printing the final result
	fmt.Println(ans)
}

// <END-OF-CODE>

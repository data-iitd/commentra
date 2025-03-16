package main

import (
	"fmt"
)

func main() {
	// Step 1: Taking input from the user
	var h, a int
	fmt.Scan(&h, &a)

	// Step 2: Calculating the number of times 'a' fits into 'h' and the remainder
	sho := h / a
	am := h % a

	// Step 3: Checking if there is a remainder and incrementing the count if necessary
	if am != 0 {
		sho++
	}

	// Step 4: Printing the result
	fmt.Println(sho)
}

// <END-OF-CODE>

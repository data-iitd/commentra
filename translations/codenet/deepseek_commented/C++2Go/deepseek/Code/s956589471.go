package main

import (
	"fmt"
)

func main() {
	// Step 3: Declare variables to store input values
	var a, b, c, d, e, k int

	// Step 4: Read input values from the user
	fmt.Scan(&a, &b, &c, &d, &e, &k)

	// Step 5: Calculate the difference between e and a and check if it is less than or equal to k
	if e - a <= k {
		fmt.Println("Yay!")
	} else {
		fmt.Println(":(")
	}

	// Step 7: Return 0 to indicate successful execution
}


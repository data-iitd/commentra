package main

import (
	"fmt"
)

func main() {
	// Step 3: Declare variables to store the input values
	var a, b, c int

	// Step 4: Read input values from the user
	fmt.Scan(&a, &b, &c)

	// Step 5: Calculate the number formed by the digits a, b, and c
	number := 100*a + 10*b + c

	// Step 6: Check if the number is divisible by 4
	if number%4 == 0 {
		// Output the result if the number is divisible by 4
		fmt.Println("YES")
	} else {
		// Output the result if the number is not divisible by 4
		fmt.Println("NO")
	}
}


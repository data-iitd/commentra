package main

import (
	"fmt"
)

func main() {
	// Step 2: Declare the necessary variables.
	var a, b, c, count int
	
	// Step 3: Read the input values for a, b, and c.
	fmt.Scanf("%d%d%d", &a, &b, &c)
	
	// Step 4: Initialize the count variable to zero.
	count = 0
	
	// Step 5: Start a for loop from a to b.
	for i := a; i <= b; i++ {
		// Step 6: Check if c is divisible by i.
		if c%i == 0 {
			// Step 7: Increment the count if the condition is true.
			count++
		}
	}
	
	// Step 8: Print the count.
	fmt.Println(count)
	
	// Step 9: Return 0 to indicate successful execution.
	// In Go, we don't need to explicitly return 0.
}

// <END-OF-CODE>

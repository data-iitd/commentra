<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
)

func main() {
	// Step 3: Read an integer input
	var n int
	fmt.Scanf("%d", &n)

	// Step 4: Perform a calculation
	// The formula (n - 2) * 180 calculates the sum of internal angles of an n-sided polygon
	var result int = (n - 2) * 180

	// Step 5: Output the result
	// The result is printed to the console
	fmt.Println(result)
}


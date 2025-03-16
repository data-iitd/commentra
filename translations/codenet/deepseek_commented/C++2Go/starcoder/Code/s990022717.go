<<<<<<< HEAD

import (
	"fmt"
)
=======
package main

import "fmt"
>>>>>>> 98c87cb78a (data updated)

func main() {
	// Read the values of n, k, x, and y from the standard input
	var n, k, x, y int
	fmt.Scanf("%d %d %d %d", &n, &k, &x, &y)

	// Initialize the sum to 0, which will accumulate the total cost
	sum := 0

	// Loop through numbers from 1 to n
	for i := 1; i <= n; i++ {
		// If the current number i is greater than k, add y to sum
		// Otherwise, add x to sum
		if i > k {
			sum += y
		} else {
			sum += x
		}
	}

	// Output the total sum, which is the cost calculated based on the input parameters
	fmt.Println(sum)
}


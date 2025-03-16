
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math"
)

// Define a type alias for long long integers
type ll int64

// Main function that starts the execution of the program
func main() {
	// Read two integers 'n' and 'd' from the standard input
	var n, d int
	fmt.Scanf("%d %d", &n, &d)

	// Calculate the value of 'a' as 'd' multiplied by 2 and adding 1
	a := float64(d*2 + 1)

	// Use the ceil function to find the smallest integer greater than or equal to the result of dividing 'n' by 'a'
	// Print the result to the standard output
	fmt.Println(int(math.Ceil(float64(n) / a)))
}


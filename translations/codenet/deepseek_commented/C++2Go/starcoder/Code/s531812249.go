<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math"
)

// Define a constant PI for representing the value of π
const PI = 3.14159265358979

// Define a type alias for long long integers
type ll int64

// Define a macro for a loop that iterates n times
func rep(i int) {
	for ; i > 0; i-- {
	}
}

// Include additional libraries for sets

func main() {
	var n, m int

	// Read two integers n and m from the standard input
	fmt.Scanf("%d %d", &n, &m)

	// n represents the number of items, m represents the number of items

	var ans int
	// Initialize a variable to store the result, which will be the sum of combinations

	// Calculate the number of ways to choose 2 items from n items (n choose 2)
	ans += n * (n - 1) / 2

	// The formula for n choose 2 is n * (n - 1) / 2
	// Add this value to the answer

	// Calculate the number of ways to choose 2 items from m items (m choose 2)
	ans += m * (m - 1) / 2

	// The formula for m choose 2 is m * (m - 1) / 2
	// Add this value to the answer

	// Output the final answer, which is the sum of combinations from n and m
	fmt.Println(ans)
}

<<<<<<< HEAD
=======
Translate the above Go code to Python and end with comment "
>>>>>>> 98c87cb78a (data updated)

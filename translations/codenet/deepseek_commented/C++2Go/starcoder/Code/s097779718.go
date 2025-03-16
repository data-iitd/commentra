<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
)

// Function to compute the greatest common divisor (GCD) using the Euclidean algorithm
func Euclid(x, y int64) int64 {
	var tmp int64

	// Ensure x is greater than y
	if x < y {
		tmp = x
		x = y
		y = tmp
	}

	// Base case: if x is divisible by y, return y
	if x%y == 0 {
		return y
	}

	// Recursive case: apply the Euclidean algorithm
	return Euclid(y, x%y)
}

func main() {
	var A, B int64

	// Read two long long integers from standard input
	fmt.Scanf("%d %d", &A, &B)

	// Calculate and output the least common multiple (LCM) of A and B
	fmt.Printf("%d\n", A*B/Euclid(A, B))
}


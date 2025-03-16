
package main

import (
	"fmt"
	"math"
)

func main() {
	// Define the modulo constant
	mod := int(math.Pow(10, 9) + 7)

	// Read input values: N (total items), A (items of type A), B (items of type B)
	var N, A, B int
	fmt.Scan(&N, &A, &B)

	// Initialize the answer variable
	ans := 0

	// Calculate how many complete cycles of (A + B) fit into N
	rep := N / (A + B)

	// Add the total items of type A from the complete cycles to the answer
	ans += rep * A

	// Calculate the remaining items after complete cycles
	res := N - rep*(A+B)

	// Add the minimum of remaining items or A to the answer
	ans += int(math.Min(float64(res), float64(A)))

	// Print the final answer
	fmt.Println(ans)
}


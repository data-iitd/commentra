
package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	// Read the number of items (N) and the total amount (X)
	N, X := readInts()

	// Initialize the answer and minimum value variables
	ans := 0 // Counter for the number of items processed
	min := 1000000000 // Initialize min to a large value

	// Process each item
	for i := 0; i < N; i++ {
		tmp := readInt() // Read the current item's value
		X -= tmp         // Subtract the item's value from total amount X
		ans++            // Increment the count of items processed
		if tmp < min {
			min = tmp // Update min if the current item is smaller
		}
	}

	// Calculate how many more items can be added using the remaining amount
	ans += X / min // Add the number of additional items that can be bought

	// Output the final answer
	fmt.Println(ans)
}

func readInts() (int, int) {
	var N, X int
	fmt.Scan(&N, &X)
	return N, X
}

func readInt() int {
	var tmp int
	fmt.Scan(&tmp)
	return tmp
}


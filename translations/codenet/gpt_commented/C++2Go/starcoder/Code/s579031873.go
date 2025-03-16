package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define type aliases for convenience
type ll int64
type P struct {
	first, second ll
}

// Global variables to hold the table, roads, and queries
var table [][]ll
var roads []P
var qs []P

func main() {
	// Read the number of items (N) and the total amount (X)
	N, X := readInt(), readInt()

	// Initialize the answer and minimum value variables
	ans := 0 // Counter for the number of items processed
	min := 1000000000 // Initialize min to a large value

	// Process each item
	for i := 0; i < N; i++ {
		tmp := readInt() // Temporary variable to hold the current item's value
		X -= tmp         // Subtract the item's value from total amount X
		ans++           // Increment the count of items processed
		if tmp < min {
			min = tmp
		}
	}

	// Calculate how many more items can be added using the remaining amount
	ans += X / min // Add the number of additional items that can be bought

	// Output the final answer
	fmt.Println(ans)
}

// readInt reads a single integer from stdin.
func readInt() int {
	var n int
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &n)
	return n
}

// END-OF-CODE

'''

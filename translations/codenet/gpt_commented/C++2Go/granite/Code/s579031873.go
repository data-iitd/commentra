
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the number of items (N) and the total amount (X)
	N, _ := strconv.Atoi(read())
	X, _ := strconv.Atoi(read())

	// Initialize the answer and minimum value variables
	ans := 0 // Counter for the number of items processed
	min := 1000000000 // Initialize min to a large value

	// Process each item
	for i := 0; i < N; i++ {
		tmp, _ := strconv.Atoi(read()) // Read the current item's value
		X -= tmp // Subtract the item's value from total amount X
		ans++ // Increment the count of items processed
		if tmp < min {
			min = tmp // Update min if the current item is smaller
		}
	}

	// Calculate how many more items can be added using the remaining amount
	ans += X / min // Add the number of additional items that can be bought

	// Output the final answer
	fmt.Println(ans)
}

func read() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}


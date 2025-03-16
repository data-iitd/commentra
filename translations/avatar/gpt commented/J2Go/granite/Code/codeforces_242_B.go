
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const (
	// Define a constant for infinity
	INF = 1e9 + 5
)

func main() {
	// Create a Scanner object for input
	sc := bufio.NewScanner(os.Stdin)

	// Read the number of pairs
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())

	// Initialize two slices to store the pairs
	a := make([]int, n)
	b := make([]int, n)

	// Initialize left to infinity and right to zero
	left, right := INF, 0

	// Read the pairs and determine the minimum and maximum values
	for i := 0; i < n; i++ {
		sc.Scan()
		a[i], _ = strconv.Atoi(sc.Text()) // Read the first element of the pair
		sc.Scan()
		b[i], _ = strconv.Atoi(sc.Text()) // Read the second element of the pair

		// Update left to the minimum value found in a
		if a[i] < left {
			left = a[i]
		}
		// Update right to the maximum value found in b
		if b[i] > right {
			right = b[i]
		}
	}

	// Check for a pair that matches the left and right bounds
	for i := 0; i < n; i++ {
		// If the current pair matches the min and max values
		if a[i] == left && b[i] == right {
			// Print the index (1-based) and exit
			fmt.Println(i + 1)
			return
		}
	}

	// If no matching pair is found, print -1
	fmt.Println(-1)
}


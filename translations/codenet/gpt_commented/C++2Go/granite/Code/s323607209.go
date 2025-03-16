
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Declare variables for the number of elements (n) and the divisor (k)
	var n, k int
	// Initialize counters for specific conditions
	l, r := 0, 0
	// Create a scanner to read input values for n and k
	scanner := bufio.NewScanner(os.Stdin)
	// Read input values for n and k
	scanner.Scan()
	fmt.Sscanf(scanner.Text(), "%d%d", &n, &k)
	// Check if k is even
	if k%2 == 0 {
		// Loop through numbers from 1 to n
		for i := 1; i <= n; i++ {
			// Count how many numbers are exactly half of k (mod k)
			if i%k == k/2 {
				l++
			}
			// Count how many numbers are multiples of k
			else if i%k == 0 {
				r++
			}
		}
		// Calculate and print the result based on the counts
		// The result is the cube of l plus the cube of r
		fmt.Println(int64(l*l*l + r*r*r))
	} else {
		// If k is odd, only count multiples of k
		for i := 1; i <= n; i++ {
			// Count how many numbers are multiples of k
			if i%k == 0 {
				r++
			}
		}
		// Print the result as the cube of r
		fmt.Println(int64(r * r * r))
	}
}

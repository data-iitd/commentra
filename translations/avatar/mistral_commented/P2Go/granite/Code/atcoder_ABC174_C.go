
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Define constants
	const mod = 1000000007

	// Create a new scanner to read input from standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read an integer from standard input and store it in a variable k
	var k int
	scanner.Scan()
	fmt.Sscanf(scanner.Text(), "%d", &k)

	// Initialize a variable t to 0
	t := 0

	// Loop from 1 to k
	for i := 1; i <= k; i++ {
		// Calculate the value of t using the current value of i and k
		t = ( (t % k) * 10 + 7 ) % k

		// Check if t is a multiple of k
		if t == 0 {
			// Print the value of i and break out of the loop
			fmt.Println(i)
			break
		}
	}

	// If the loop completes without finding a multiple of k, print -1
	if t!= 0 {
		fmt.Println(-1)
	}
}


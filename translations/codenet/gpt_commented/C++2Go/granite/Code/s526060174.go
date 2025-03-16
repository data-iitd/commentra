
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Declare variables for the number of groups (n) and the maximum number (m)
	var n, m int
	// Declare variables for the number of elements in each group (k) and the individual element (a)
	var k, a int
	// Array to count occurrences of each number from 1 to m
	x := make([]int, 31)
	// Initialize the answer variable to count how many numbers appear in all groups
	ans := 0

	// Read the number of groups (n) and the maximum number (m)
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d %d\n", &n, &m)

	// Loop through each group
	for i := 0; i < n; i++ {
		// Read the number of elements in the current group
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &k)
		// Loop through each element in the current group
		for j := 0; j < k; j++ {
			// Read the element and increment its count in the array
			fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &a)
			x[a]++
		}
	}

	// Check each number from 1 to m
	for i := 1; i <= m; i++ {
		// If the number appears in all n groups, increment the answer
		if x[i] == n {
			ans++
		}
	}

	// Output the final count of numbers that appeared in all groups
	fmt.Println(ans)
}


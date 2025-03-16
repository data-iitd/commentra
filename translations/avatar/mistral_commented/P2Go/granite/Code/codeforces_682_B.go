
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	// Read the number of test cases 'n' from standard input
	n, _ := fmt.Fscanf(os.Stdin, "%d\n", &n)

	// Read the list 'l' of length 'n' containing 'n' integers
	l := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(os.Stdin, "%d", &l[i])
	}

	// Sort the list 'l' in ascending order
	sort.Ints(l)

	// Initialize variable 'c' to 0
	c := 0

	// Iterate through the list 'l'
	for i := 0; i < n; i++ {
		// If the current element 'l[i]' is greater than the previous count 'c', increment 'c' by 1
		if l[i] > c {
			c++
		}
	}

	// Print the final result, which is the number of unique elements in the list 'l' plus 1
	fmt.Println(c + 1)
}


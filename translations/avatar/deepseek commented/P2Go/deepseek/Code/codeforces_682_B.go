package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	// Read the number of elements
	scanner.Scan()
	n := 0
	fmt.Sscan(scanner.Text(), &n)

	// Read the list of elements
	l := make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &l[i])
	}

	// Initialize variables
	f := 1  // Flag variable
	sort.Ints(l)  // Sort the list
	c := 0  // Counter variable

	// Iterate through the list to find the maximum number of unique elements
	for _, i := range l {
		if i > c {
			c += 1  // Increment the counter if the current element is greater than the counter
		}
	}

	// Print the result
	fmt.Println(c + 1)  // Print the maximum number of unique elements
}

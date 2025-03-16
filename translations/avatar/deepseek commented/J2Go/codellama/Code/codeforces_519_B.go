
package main

import (
	"fmt"
	"os"
	"bufio"
	"strconv"
)

func main() {
	// Create a Scanner object to read input from the standard input stream
	sc := bufio.NewScanner(os.Stdin)

	// Read the number of elements
	n, _ := strconv.Atoi(sc.Text())

	// Initialize sums of subsets
	a := 0
	b := 0
	c := 0

	// Sum all n elements
	for i := 0; i < n; i++ {
		a += sc.Text()
	}

	// Sum n-1 elements
	for i := 0; i < n-1; i++ {
		b += sc.Text()
	}

	// Sum n-2 elements
	for i := 0; i < n-2; i++ {
		c += sc.Text()
	}

	// Calculate the differences
	x := a - b
	y := b - c

	// Output the results
	fmt.Println(x)
	fmt.Println(y)
}


package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	// Creating scanner object for reading input from the standard input
	scanner := bufio.NewScanner(os.Stdin)
	// Creating print writer object for writing output to the standard output
	stdout := bufio.NewWriter(os.Stdout)
	defer stdout.Flush()

	// Reading the number of elements in the list from the input
	scanner.Scan()
	n, _ := fmt.Sscan(scanner.Text(), &n)

	// Creating a slice of size 'n' to store the elements
	list := make([]int, n)

	// Reading 'n' elements from the input and adding them to the slice
	for i := 0; i < n; i++ {
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &list[i])
	}

	// Sorting the slice in ascending order using sort.Ints() function
	sort.Ints(list)

	// Initializing a variable 'c' to keep track of the number of distinct elements
	c := 1

	// Iterating through the slice to find the number of distinct elements
	for i := 0; i < n; i++ {
		// If the current element is greater than or equal to the current count 'c', increment the count
		if list[i] >= c {
			c++
		}
	}

	// Writing the result to the output
	fmt.Fprintln(stdout, c)

	// Debugging method to print the deep toString representation of an object
	debug := func(obj ...interface{}) {
		fmt.Fprintln(os.Stderr, obj)
	}
}


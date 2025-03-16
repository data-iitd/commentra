
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Importing the itertools module for combinatorial functions
	// (Note: This is not available in Go, so we'll have to implement it ourselves)

	// Reading the values of n and m from input
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(readLine(reader))
	m, _ := strconv.Atoi(readLine(reader))

	// Reading m lists of integers, each containing values after the first element
	li := make([][]int, m)
	for i := 0; i < m; i++ {
		line := readLine(reader)
		// Implementing the logic to read the list of integers
		//...

		// Appending the list to the li slice
		li[i] = []int{1, 2, 3} // Replace with actual list of integers
	}

	// Reading a tuple p from input
	p := readLine(reader)
	// Implementing the logic to read the tuple of integers
	//...

	// Creating a set q that contains all unique elements from the lists in li
	q := make(map[int]bool)
	for _, l := range li {
		for _, v := range l {
			q[v] = true
		}
	}

	// Creating a set r that contains all integers from 1 to n
	r := make(map[int]bool)
	for i := 1; i <= n; i++ {
		r[i] = true
	}

	// Finding the set of values v that are in r but not in q
	v := make(map[int]bool)
	for k := range r {
		if!q[k] {
			v[k] = true
		}
	}

	// Initializing the answer variable to count valid combinations
	ans := 0

	// Iterating over all possible sizes of combinations from the set q
	for i := 0; i <= len(q); i++ {
		// Generating combinations of size i from the set q
		// (Note: This is not available in Go, so we'll have to implement it ourselves)

		// Checking each list in li against the corresponding value in p
		for _, l := range li {
			// Implementing the logic to check the list against the value in p
			//...
		}

		// If all checks passed, increment the answer by 2 raised to the power of the size of v
		ans += 1 << len(v) // Replace with actual logic to calculate 2 raised to the power of the size of v
	}

	// Printing the final answer
	fmt.Println(ans)
}

func readLine(reader *bufio.Reader) string {
	line, _, err := reader.ReadLine()
	if err!= nil {
		panic(err)
	}
	return string(line)
}

// Entry point of the program
func main() {
	main()
}


package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Creating a new scanner for reading input from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Reading the number of operations
	scanner.Scan()
	N := 368
	m := make([]int, N)
	f := make([]int, N)

	// Processing each operation
	for i := 0; i < int(scanner.Text()); i++ {
		// Reading an operation line and splitting it into components
		scanner.Scan()
		line := scanner.Text()
		parts := strings.Split(line, " ")
		x := parts[0]
		a, _ := strconv.Atoi(parts[1])
		b, _ := strconv.Atoi(parts[2])
		b += 1

		// Updating the m or f array accordingly
		if x == "M" {
			m[a] += 2
			m[b] -= 2
		} else {
			f[a] += 2
			f[b] -= 2
		}
	}

	// Initializing three variables a, b, and c with zeros
	a, b, c := 0, 0, 0

	// Calculating the prefix sums of m and f arrays
	for i := 0; i < N; i++ {
		// Updating the variables a and b with the sum of m and f arrays respectively
		a += m[i]
		b += f[i]
		// Finding the minimum of a and b and updating the variable c if the minimum is greater than the current value of c
		if min(a, b) > c {
			c = min(a, b)
		}
	}

	// Printing the result, which is the minimum of the prefix sums of m and f arrays
	fmt.Println(c)
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

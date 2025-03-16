// Importing the fmt and strconv modules for reading input from the standard input
package main

import (
	"fmt"
	"strconv"
)

// Assigning the function readline to the variable input for reading lines from standard input
func input() string {
	var s string
	fmt.Scan(&s)
	return s
}

// Initializing the arrays m and f with zeros for all indices up to N
var N = 368
var m = make([]int, N)
var f = make([]int, N)

// Reading the number of operations from the standard input and processing each operation
for i := 0; i < int(input()); i++ {
	// Reading an operation line and splitting it into components
	x, a, b := input(), input(), input()
	// Converting the components a and b to integers
	a, _ = strconv.Atoi(a)
	b, _ = strconv.Atoi(b)
	// If the operation is 'M', updating the m array accordingly
	if x == "M" {
		m[a] += 2
		m[b] -= 2
	}
	// If the operation is 'F', updating the f array accordingly
	else {
		f[a] += 2
		f[b] -= 2
	}
}

// Initializing three variables a, b, and c with zeros
var a, b, c int

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

// Defining the min function for finding the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// End of code

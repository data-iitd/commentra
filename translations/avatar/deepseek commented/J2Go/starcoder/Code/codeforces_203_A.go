package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Reading the number of test cases (t) and other required values
	x := readInt() // Target value x
	t := readInt() // Number of test cases (unused in this code)
	a := readInt() // Value a
	b := readInt() // Value b
	da := readInt() // Difference a (da)
	db := readInt() // Difference b (db)

	// Variables to store calculated values
	first := 0
	second := 0

	// Flag to determine if a solution is found
	ok := false

	// Nested loop to calculate possible values of first and second
	for i := 0; i < t; i++ {
		first = a - (da * i) // Calculate first value
		for j := 0; j < t; j++ {
			second = b - (db * j) // Calculate second value
			if second+first == x || second == x || first == x || x == 0 {
				// Check if the sum of first and second equals x, or if either value equals x, or if x is zero
				ok = true
				break
			}
		}
		if ok {
			break
		}
	}

	// Print the result based on the flag
	if ok {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

// readInt reads a single integer from stdin.
func readInt() int {
	var i int
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &i)
	return i
}


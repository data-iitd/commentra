
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Set up input reading methods for efficient reading from standard input
	read := func() []byte {
		return []byte(os.Stdin.ReadString('\n'))
	}
	readline := func() string {
		return string(read())
	}
	readlines := func() []string {
		return []string{readline()}
	}

	// Read the input values for N, d, and x, and convert them to integers
	N, _ := strconv.Atoi(readline())
	d, _ := strconv.Atoi(readline())
	x, _ := strconv.Atoi(readline())

	// Initialize the result variable to accumulate the final value
	ret := 0

	// Loop until N becomes zero
	for N > 0 {
		// Update the result by adding the current d and a calculated value based on N and x
		ret += d + (N-0.5)*float64(x)

		// Update d based on its current value, N, and x
		d += d / float64(N) + (5 * float64(x)) / (2 * float64(N))

		// Update x based on its current value and N
		x += 2 * float64(x) / float64(N)

		// Decrement N to move to the next iteration
		N--
	}

	// Return the accumulated result
	fmt.Println(ret)
}

// 
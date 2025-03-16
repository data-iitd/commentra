package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the input values for N, d, and x, and convert them to integers
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	N, _ := strconv.Atoi(line)
	line, _ = reader.ReadString('\n')
	line = strings.TrimSpace(line)
	d, _ := strconv.Atoi(line)
	line, _ = reader.ReadString('\n')
	line = strings.TrimSpace(line)
	x, _ := strconv.Atoi(line)

	// Initialize the result variable to accumulate the final value
	ret := 0

	// Loop until N becomes zero
	for N > 0 {
		// Update the result by adding the current d and a calculated value based on N and x
		ret += d + (N-0.5)*x

		// Update d based on its current value, N, and x
		d += d/N + 5*x/(2*N)

		// Update x based on its current value and N
		x += 2*x/N

		// Decrement N to move to the next iteration
		N--
	}

	// Return the accumulated result
	fmt.Println(ret)
}

// 
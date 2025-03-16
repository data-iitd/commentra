
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function A is not defined in the provided code.
func A() {
	// Function implementation here (if needed)
}

// Function B is defined to take input and calculate the number of iterations.
func B() {
	x, sum := 0, 100
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d\n", &x)
	i := 0 // Initialize i to 0
	for sum < x {
		i++
		sum += sum / 100 // Increment sum by 1%
	}
	fmt.Println(i) // Output the number of iterations
}

// Function C is not defined in the provided code.
func C() {
	// Function implementation here (if needed)
}

// Function D is not defined in the provided code.
func D() {
	// Function implementation here (if needed)
}

// Main function calls the B function.
func main() {
	B()
}


package main

import (
	"fmt"
	"math"
)

// Define a large constant for infinity
const inf = 1e20

// Define a modulus value commonly used in competitive programming
const mod = 1e9 + 7

// Define directional movements for 4 directions (up, right, down, left)
var dd = [][2]int{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}

// Define diagonal movements for 8 directions (including diagonals)
var ddn = [][2]int{{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}}

// Function to read a line of input and return it as a slice of integers
func readInts() []int {
	var a, b, c, d int
	fmt.Scan(&a, &b, &c, &d)
	return []int{a, b, c, d}
}

// Main function to execute the core logic of the program
func main() {
	// Read four integers from input
	a, b, c, d := readInts()[0], readInts()[1], readInts()[2], readInts()[3]

	// Calculate the maximum value from the products of the pairs and return it
	result := int(math.Max(float64(a*c), math.Max(float64(b*d), math.Max(float64(a*d), float64(b*c)))))
	
	// Print the result
	fmt.Println(result)
}

// <END-OF-CODE>

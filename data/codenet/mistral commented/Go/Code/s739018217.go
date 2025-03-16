
package main

import (
	"fmt"
	"math"
)

// Function main is the entry point of the program
func main() {
	// Declare and initialize two integer variables n and m using fmt.Scan
	var n, m int
	fmt.Scan(&n, &m)

	// Calculate the value of x using the given formula
	x := m*1900 + (n-m)*100

	// Print the result using fmt.Println
	fmt.Println(x * int(math.Pow(2.0, float64(m))))
}


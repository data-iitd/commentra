package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	// Set a high recursion limit (not directly applicable in Go)
	// Go does not have a recursion limit like Python, but we can manage stack size if needed.

	// Define a debug print function that only prints if running in a terminal environment
	dbg := func(args ...interface{}) {
		if _, ok := os.LookupEnv("TERM_PROGRAM"); ok {
			fmt.Println(args...)
		}
	}

	// Read two values from input: one as an integer and the other as a float in string format
	var sa, sb string
	fmt.Scan(&sa, &sb)

	// Convert the first value to an integer
	a, _ := strconv.Atoi(sa)

	// Convert the second value to an integer representing cents (by multiplying by 100)
	bFloat, _ := strconv.ParseFloat(sb, 64)
	b := int(math.Round(bFloat * 100))

	// Calculate and print the product of a and b, divided by 100 to get the final result
	fmt.Println(a * b / 100)
}

// <END-OF-CODE>

package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Set the recursion limit (not directly applicable in Go, but we can manage stack size)
	// Go has a different approach to recursion limits, so we won't set it explicitly.

	// Define a debug function to print debug messages
	setDebug := func(something ...interface{}) {
		if _, ok := os.LookupEnv("TERM_PROGRAM"); ok {
			fmt.Println(something...)
		}
	}

	// Read input for two numbers 'a' and 'b'
	var input string
	fmt.Scanln(&input)
	parts := strings.Fields(input)
	sa := parts[0]
	sb := parts[1]

	a, _ := strconv.Atoi(sa)
	bFloat, _ := strconv.ParseFloat(sb, 64)
	b := int(math.Round(bFloat * 100))

	// Calculate the product of 'a' and 'b' and print the result
	fmt.Println(a * b / 100)
}

// <END-OF-CODE>

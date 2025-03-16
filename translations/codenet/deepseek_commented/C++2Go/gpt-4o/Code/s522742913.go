package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	// Step 1: Input Handling
	var source string
	fmt.Scan(&source)

	// Check if the length of the input string is within the valid range (1 to 10 characters).
	if len(source) > 10 || len(source) < 1 {
		return
	}

	// Step 2: Calculation Setup
	// Calculate the maximum number of combinations that can be formed
	// by placing '+' signs between the digits of the input string.
	maxI := int(math.Pow(2, float64(len(source)-1)))

	// Step 3: Iterating Over Combinations
	var sum float64

	for i := 0; i < maxI; i++ {
		plus := fmt.Sprintf("%b", i)
		plus = fmt.Sprintf("%0*s", len(source)-1, plus) // Pad with leading zeros

		number := 0.0
		working := source
		start := 0

		for j := 0; j < len(plus); j++ {
			if plus[j] == '1' {
				// If we encounter a '1', we add the current substring to the sum
				num, _ := strconv.ParseFloat(working[:j+1-start], 64)
				sum += num
				start = j + 1
			}
		}
		// Add the last remaining part of the string
		if start < len(working) {
			num, _ := strconv.ParseFloat(working[start:], 64)
			sum += num
		}
	}

	// Step 4: Output
	fmt.Printf("%.0f\n", sum)
}

// <END-OF-CODE>

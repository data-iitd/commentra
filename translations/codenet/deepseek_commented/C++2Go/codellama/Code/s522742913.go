package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	// Step 1: Input Handling
	// The program starts by taking a string input from the user.
	var source string
	fmt.Scan(&source)

	// It checks if the length of the input string is within the valid range (1 to 10 characters).
	// If not, it returns -1.
	if len(source) > 10 || len(source) < 1 {
		fmt.Println(-1)
		return
	}

	// Step 2: Calculation Setup
	// The program calculates the maximum number of combinations that can be formed
	// by placing '+' signs between the digits of the input string.
	// This is done using the formula 2^(n-1), where n is the length of the input string.
	max_i := int(math.Pow(2, float64(len(source)-1)))

	// Step 3: Iterating Over Combinations
	// The program iterates over all possible combinations of placing '+' signs between the digits.
	// For each combination, it calculates the sum of the numbers formed by the substrings separated by '+' signs.
	sum := 0.0

	for i := 0; i < max_i; i++ {
		plus := strconv.FormatInt(int64(i), 2)

		number := 0.0

		working := source
		for plus != "0" {
			i := strings.Index(plus, "1")
			sum += atof(working[:i+1])
			plus = plus[i+1:]
			working = working[i+1:]
		}
		sum += atof(working)
	}

	// Step 4: Output
	// Finally, the program outputs the sum of all possible combinations.
	fmt.Println(sum)
}

func atof(s string) float64 {
	f, _ := strconv.ParseFloat(s, 64)
	return f
}


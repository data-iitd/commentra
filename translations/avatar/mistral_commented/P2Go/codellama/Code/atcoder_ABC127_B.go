package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	// Take three integers as input from the user
	r, D, x := map(strconv.Atoi, strings.Split(input(), " "))

	// Iterate through the range of numbers from 2 to 11 (12 is excluded)
	for i := 2; i < 12; i++ {
		// Calculate the expression and print the integer result
		fmt.Println(int(math.Round(math.Pow(r, float64(i-1)) * (float64(x) + D / (1 - r)) - D / (1 - r))))
	}
}

// The expression inside the loop calculates the value of a recursive formula
// r^(i-1) * (x + D / (1 - r)) - D / (1 - r)


Translate the above Go code to C++ and end with comment "
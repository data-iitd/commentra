package main

import (
	"fmt"
	"math"
	"strings"
)

func main() {
	// Read the input from the standard input
	var a string
	fmt.Scan(&a)

	// Check if the string contains any '1' character
	if strings.Count(a, "1") == 0 {
		// If it doesn't, print 0 and exit the program
		fmt.Println(0)
		return
	}

	// If the string contains at least one '1' character, we proceed to calculate the product of the number of zeros in each segment between consecutive '1' characters
	productOfZeros := math.Prod([]float64{float64(strings.Count(a, "0") + 1)})

	// Finally, print the result
	fmt.Println(productOfZeros)
}


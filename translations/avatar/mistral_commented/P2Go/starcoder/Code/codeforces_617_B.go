package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the input from the standard input
	a := os.Stdin.ReadString('\n')

	// Check if the string contains any '1' character
	if strings.Count(a, "1") == 0 {
		// If it doesn't, print 0 and exit the program
		fmt.Println(0)
		return
	}

	// If the string contains at least one '1' character, we proceed to calculate the product of the number of zeros in each segment between consecutive '1' characters
	product_of_zeros := 1
	for _, i := range strings.Split(strings.Trim(a, "0"), "1") {
		product_of_zeros *= len(i) + 1
	}

	// Finally, print the result
	fmt.Println(product_of_zeros)
}


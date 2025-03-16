
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a Scanner object to read input from the console
	sc := bufio.NewScanner(os.Stdin)

	// Read two integers A and B from the input
	sc.Scan()
	A, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	B, _ := strconv.Atoi(sc.Text())

	// Initialize variables to hold the remainder and the result
	amari := 0
	result := 0

	// Calculate the initial result based on the formula (B - 1) / (A - 1)
	result = (B - 1) / (A - 1)

	// Calculate the remainder when (B - 1) is divided by (A - 1)
	amari = (B - 1) % (A - 1)

	// If there is a remainder, increment the result by 1
	if amari!= 0 {
		result += 1
	}

	// Print the final result to the console
	fmt.Println(result)
}


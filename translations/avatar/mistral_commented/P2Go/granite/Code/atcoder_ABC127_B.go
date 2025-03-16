
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a scanner to read input from the user
	scanner := bufio.NewScanner(os.Stdin)

	// Read three integers from the user
	scanner.Scan()
	line := scanner.Text()
	parts := strings.Split(line, " ")
	r, _ := strconv.Atoi(parts[0])
	D, _ := strconv.Atoi(parts[1])
	x, _ := strconv.Atoi(parts[2])

	// Iterate through the range of numbers from 2 to 11 (12 is excluded)
	for i := 2; i < 12; i++ {
		// Calculate the expression and print the integer result
		result := int(float64(r^(i-1)) * float64(x+D/(1-float64(r))) - float64(D/(1-float64(r))))
		fmt.Println(result)
	}
}

// The expression inside the loop calculates the value of a recursive formula
// r^(i-1) * (x + D / (1 - r)) - D / (1 - r)


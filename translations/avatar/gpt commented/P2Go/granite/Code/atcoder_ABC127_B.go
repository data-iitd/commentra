
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read input values for r, D, and x from the user
	reader := bufio.NewReader(os.Stdin)
	rStr, _ := reader.ReadString(' ')
	DStr, _ := reader.ReadString(' ')
	xStr, _ := reader.ReadString('\n')
	r, _ := strconv.ParseFloat(rStr, 64)
	D, _ := strconv.ParseFloat(DStr, 64)
	x, _ := strconv.ParseFloat(xStr, 64)

	// Iterate over a range of values from 2 to 11 (inclusive)
	for i := 2; i <= 11; i++ {
		// Calculate and print the result based on the formula
		// The formula computes a value using the current iteration index i,
		// the input values r, D, and x, and prints the integer result
		fmt.Println(int((math.Pow(r, float64(i-1))) * (x + D/(1-r)) - D/(1-r)))
	}
}

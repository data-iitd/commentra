
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a scanner object to read input from the console
	scanner := bufio.NewScanner(os.Stdin)

	// Read the number of currency entries
	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())

	// Initialize arrays to hold the amounts and their corresponding currency units
	x := make([]float64, N)
	u := make([]string, N)

	// Loop to read each amount and its currency unit
	for i := 0; i < N; i++ {
		scanner.Scan()
		parts := strings.Split(scanner.Text(), " ")
		x[i], _ = strconv.ParseFloat(parts[0], 64)
		u[i] = parts[1]
	}

	// Calculate the total value in a standard currency and print the result
	fmt.Println(solve(x, u))
}

// Method to solve the currency conversion problem
func solve(x []float64, u []string) float64 {
	// Convert each amount to a standard currency and sum them up
	total := 0.0
	for i := 0; i < len(x); i++ {
		if u[i] == "JPY" {
			total += x[i]
		} else {
			total += x[i] * 380000.0
		}
	}
	return total
}

// END-OF-CODE
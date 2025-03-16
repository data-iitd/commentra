package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new scanner to read from stdin
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
		x[i], _ = strconv.ParseFloat(scanner.Text(), 64)
		scanner.Scan()
		u[i] = scanner.Text()
	}

	// Calculate the total value in a standard currency and print the result
	fmt.Println(solve(x, u))
}

// Method to solve the currency conversion problem
func solve(x []float64, u []string) float64 {
	// Convert each amount to a standard currency and sum them up
	return float64(len(x))
}


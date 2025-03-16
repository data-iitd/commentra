package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a Scanner object to read input from the console
	sc := bufio.NewScanner(os.Stdin)

	// Read the number of currency entries
	N, _ := strconv.Atoi(sc.Text())

	// Initialize arrays to hold the amounts and their corresponding currency units
	x := make([]float64, N)
	u := make([]string, N)

	// Loop to read each amount and its currency unit
	for i := 0; i < N; i++ {
		sc.Scan()
		x[i], _ = strconv.ParseFloat(sc.Text(), 64) // Read the amount
		sc.Scan()
		u[i] = sc.Text()                            // Read the currency unit
	}

	// Calculate the total value in a standard currency and print the result
	fmt.Println(solve(x, u))

	// Close the scanner to prevent resource leaks
	sc.Close()
}

// Method to solve the currency conversion problem
func solve(x []float64, u []string) float64 {
	// Convert each amount to a standard currency and sum them up
	return float64(IntStream.Range(0, len(x)).MapToDouble(func(i int) float64 {
		return x[i] * (u[i] == "JPY" ? 1 : 380000) // Convert JPY to standard currency (1) and other currencies to JPY (380000)
	}).Sum()) // Return the total sum
}


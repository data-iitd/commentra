package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var N int
	fmt.Scan(&N) // Take an integer input N, which represents the number of elements.

	x := make([]float64, N) // Create a slice x to hold the converted values.

	for i := 0; i < N; i++ {
		var input string
		fmt.Scan(&input) // Read the input string.

		// Replace 'JPY' with '1.0' and 'BTC' with '380000.0'
		input = strings.ReplaceAll(input, "JPY", "1.0")
		input = strings.ReplaceAll(input, "BTC", "380000.0")

		// Convert the modified string to a float64
		value, err := strconv.ParseFloat(input, 64)
		if err != nil {
			fmt.Println("Error parsing input:", err)
			return
		}
		x[i] = value // Store the converted value in the slice.
	}

	// Calculate the sum of the elements in the slice x
	var total float64
	for _, value := range x {
		total += value
	}

	fmt.Println(total) // Print the sum of the elements in the slice x.
}

// <END-OF-CODE>

package main

import (
	"fmt"
	"strconv"
)

func main() {
	// Create a Scanner object to read input from the user
	sc := new(Scanner)

	// Read an integer input from the user
	n, _ := strconv.Atoi(sc.next())

	// Initialize a variable to hold the final result
	ans := 0

	// Loop through each integer from 1 to n (inclusive)
	for i := 1; i < n+1; i++ {
		// Calculate the contribution of the current integer i to the result
		// This involves multiplying i by the number of times i fits into n
		// and summing up the series of numbers from 1 to (n / i)
		ans += i * (n / i) * (n/i + 1) / 2
	}

	// Output the final result
	fmt.Println(ans)
}

// 
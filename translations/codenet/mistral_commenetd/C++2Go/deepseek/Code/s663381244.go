package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Initialize cin and ios streams to disable buffering and synchronization
	// In Go, we don't have a direct equivalent to cin and ios, but we can use bufio for input and fmt for output
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Initialize an empty slice 'm' to store the multipliers
	var m = []int{10, 50, 100, 500}

	// Main loop to read the input money and calculate the change
	for {
		// Read the input money
		fmt.Fscan(reader, &money)
		if money == 0 {
			break
		}

		// Initialize variables 'sum' and 'num'
		var sum int
		var num = [4]int{}

		// Read the numbers and calculate the sum of the products of each number and its corresponding multiplier
		for i := 0; i < 4; i++ {
			fmt.Fscan(reader, &num[i])
			sum += num[i] * m[i]
		}

		// Calculate the change
		var change = sum - money

		// Adjust the numbers to get the exact change
		for i := 3; i >= 0; i-- {
			// If the change is divisible by the current multiplier, subtract the required number of multipliers and update the change
			if change >= m[i] {
				num[i] -= change / m[i]
				change %= m[i]
			}
		}

		// Print the numbers that still have a positive value
		for i := 0; i < 4; i++ {
			if num[i] > 0 {
				fmt.Fprintln(writer, m[i], num[i])
			}
		}
	}
}


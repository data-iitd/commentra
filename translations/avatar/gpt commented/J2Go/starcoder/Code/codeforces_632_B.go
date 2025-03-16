package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of elements in the array
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter the number of elements in the array: ")
	input, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(input))

	// Initialize an array to hold the integer values
	a := make([]int, n)

	// Populate the array with input values
	for i := 0; i < n; i++ {
		fmt.Printf("Enter the value of a[%d]: ", i)
		input, _ := reader.ReadString('\n')
		a[i], _ = strconv.Atoi(strings.TrimSpace(input))
	}

	// Read the string input which consists of characters 'A' and 'B'
	fmt.Print("Enter the string input which consists of characters 'A' and 'B': ")
	input, _ = reader.ReadString('\n')
	s := strings.TrimSpace(input)

	// Initialize a variable to hold the sum of values corresponding to 'B'
	sum := 0

	// Calculate the initial sum based on the positions of 'B' in the string
	for i := 0; i < len(s); i++ {
		if s[i] == 'B' {
			sum += a[i]
		}
	}

	// Store the initial sum as the maximum answer found so far
	ans := sum

	// Iterate through the string to calculate the maximum possible sum
	for i := 0; i < len(s); i++ {
		if s[i] == 'A' {
			sum += a[i]
		} else {
			sum -= a[i]
		}

		// Update the maximum answer if the current sum is greater
		if sum > ans {
			ans = sum
		}
	}

	// Reset sum to the initial sum for the next calculation
	sum = ans

	// Iterate through the string in reverse to calculate the maximum possible sum
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] == 'A' {
			sum += a[i]
		} else {
			sum -= a[i]
		}

		// Update the maximum answer if the current sum is greater
		if sum > ans {
			ans = sum
		}
	}

	// Output the maximum sum found
	fmt.Printf("The maximum sum found is: %d\n", ans)
}


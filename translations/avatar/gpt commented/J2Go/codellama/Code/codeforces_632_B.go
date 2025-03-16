package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a Scanner object to read input from the console
	sc := bufio.NewScanner(os.Stdin)

	// Read the number of elements in the array
	n, _ := strconv.Atoi(sc.Text())

	// Initialize an array to hold the integer values
	a := make([]int, n)

	// Populate the array with input values
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(sc.Text())
	}

	// Read the string input which consists of characters 'A' and 'B'
	s := sc.Text()

	// Initialize a variable to hold the sum of values corresponding to 'B'
	sum := 0

	// Calculate the initial sum based on the positions of 'B' in the string
	for i := 0; i < len(s); i++ {
		if s[i] == 'B' {
			sum += a[i] // Add the value to sum if the character is 'B'
		}
	}

	// Store the initial sum as the maximum answer found so far
	ans := sum
	sum1 := sum

	// Iterate through the string to calculate the maximum possible sum
	for i := 0; i < len(s); i++ {
		if s[i] == 'A' {
			sum1 += a[i] // Increase sum1 if the character is 'A'
		} else {
			sum1 -= a[i] // Decrease sum1 if the character is not 'A'
		}

		// Update the maximum answer if the current sum1 is greater
		if sum1 > ans {
			ans = sum1
		}
	}

	// Reset sum1 to the initial sum for the next calculation
	sum1 = sum

	// Iterate through the string in reverse to calculate the maximum possible sum
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] == 'A' {
			sum1 += a[i] // Increase sum1 if the character is 'A'
		} else {
			sum1 -= a[i] // Decrease sum1 if the character is not 'A'
		}

		// Update the maximum answer if the current sum1 is greater
		if sum1 > ans {
			ans = sum1
		}
	}

	// Output the maximum sum found
	fmt.Println(ans)
}



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
	reader := bufio.NewReader(os.Stdin)

	// Read the number of elements in the array
	n, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())-1])

	// Initialize an array to hold the integer values
	a := make([]int, n)

	// Populate the array with input values
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())-1])
	}

	// Read the string input which consists of characters 'A' and 'B'
	s := reader.ReadLine()[2 : len(reader.ReadLine())-1]

	// Initialize a variable to hold the sum of values corresponding to 'B'
	sum := int64(0)

	// Calculate the initial sum based on the positions of 'B' in the string
	for i := 0; i < len(s); i++ {
		if s[i] == 'B' {
			sum += int64(a[i])
		}
	}

	// Store the initial sum as the maximum answer found so far
	ans := sum

	// Initialize a variable to hold the sum of values corresponding to 'B'
	sum1 := sum

	// Iterate through the string to calculate the maximum possible sum
	for i := 0; i < len(s); i++ {
		if s[i] == 'A' {
			sum1 += int64(a[i])
		} else {
			sum1 -= int64(a[i])
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
			sum1 += int64(a[i])
		} else {
			sum1 -= int64(a[i])
		}

		// Update the maximum answer if the current sum1 is greater
		if sum1 > ans {
			ans = sum1
		}
	}

	// Output the maximum sum found
	fmt.Println(ans)
}

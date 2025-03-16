package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Reading the number of elements in the array from the standard input
	a := make([]int, n) // Creating an integer slice of size n

	for i := 0; i < n; i++ { // Iterating through the slice to read its elements from the standard input
		fmt.Scan(&a[i])
	}

	var s string
	fmt.Scan(&s) // Reading the string from the standard input
	sum := 0 // Initializing the sum variable to zero

	for i := 0; i < len(s); i++ { // Iterating through the string to calculate the sum of the slice elements corresponding to the 'B' characters
		if s[i] == 'B' {
			sum += a[i]
		}
	}

	ans := sum // Initializing the answer variable with the sum calculated above
	sum1 := sum // Initializing a temporary sum variable with the sum calculated above

	for i := 0; i < len(s); i++ { // Iterating through the string to calculate the sum of the slice elements corresponding to the 'A' characters and subtracting the sum of the slice elements corresponding to the 'B' characters to find the maximum sum
		if s[i] == 'A' {
			sum1 += a[i]
		} else {
			sum1 -= a[i]
		}
		if sum1 > ans {
			ans = sum1
		}
	}

	sum1 = sum // Resetting the temporary sum variable with the sum calculated at the beginning

	for i := len(s) - 1; i >= 0; i-- { // Iterating through the string in reverse order to calculate the sum of the slice elements corresponding to the 'A' characters and subtracting the sum of the slice elements corresponding to the 'B' characters to find the maximum sum
		if s[i] == 'A' {
			sum1 += a[i]
		} else {
			sum1 -= a[i]
		}
		if sum1 > ans {
			ans = sum1
		}
	}

	fmt.Println(ans) // Printing the maximum sum found
}

// <END-OF-CODE>

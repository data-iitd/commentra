package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	// Take an integer input 'n' from the user
	var n int
	fmt.Scan(&n)

	// Take 'n' floating point numbers as input and store them in a list 'arr'
	var arr []float64
	var input string
	fmt.Scan(&input)
	arr = strings.Split(input, " ")
	for i := 0; i < len(arr); i++ {
		arr[i], _ = strconv.ParseFloat(arr[i], 64)
	}

	// Filter out the integers from the list 'arr' and sort the remaining floating point numbers
	var filtered []float64
	for i := 0; i < len(arr); i++ {
		if arr[i]-math.Floor(arr[i]) != 0 {
			filtered = append(filtered, arr[i])
		}
	}
	arr = filtered
	arr = append(arr[:0], arr[len(arr)-n:]...)

	// Calculate the length of the filtered list 'arr' and assign it to the variable 'o'
	o := 2*n - len(arr)

	// Calculate the sum of all the floating point numbers in the list 'arr' and assign it to the variable 'arr_sum'
	var arr_sum float64
	for i := 0; i < len(arr); i++ {
		arr_sum += arr[i]
	}

	// Initialize the variable 'res' with a large integer value
	res := int(2e9)

	// Iterate through the range from 0 to n+1
	for i := 0; i < n+1; i++ {
		// Check if the index 'i' plus the offset 'o' is greater than or equal to 'n'
		if i+o >= n {
			// Update the minimum value of 'res' with the absolute difference between 'i' and 'arr_sum'
			res = int(math.Min(float64(res), math.Abs(float64(i)-arr_sum)))
		}
	}

	// Print the result with three decimal places
	fmt.Printf("%.3f", float64(res))
}


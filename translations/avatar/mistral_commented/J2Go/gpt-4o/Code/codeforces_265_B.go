package main

import (
	"fmt"
	"math"
)

func main() {
	// Create a variable n to read the size of the array
	var n int
	fmt.Scan(&n)

	// Create a slice arr of size n
	arr := make([]int, n)

	// Use a for loop to read n integers from the standard input and store them in the slice arr
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i]) // Read the next integer and store it in the current index of the slice
	}

	// Initialize a variable ans with the first element of the slice and add 1 to it
	ans := arr[0] + 1

	// Use another for loop to iterate through the remaining elements of the slice arr
	for i := 1; i < n; i++ {
		// Calculate the absolute difference between the current and previous elements and add it to the variable ans along with 2
		ans += int(math.Abs(float64(arr[i] - arr[i-1]))) + 2
	}

	// Finally, print the value of ans to the standard output
	fmt.Println(ans)
}

// <END-OF-CODE>

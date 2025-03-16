package main

import (
	"fmt"
)

func main() {
	var n, m, x int // Declare three integer variables n, m, and x
	fmt.Scanf("%d %d %d", &n, &m, &x) // Read three integers from the standard input

	a := make([]int, 106) // Declare and initialize a slice a of size 106 with zeros

	for i := 0; i < m; i++ { // Iterate through m times
		var temp int // Declare a temporary variable temp
		fmt.Scanf("%d", &temp) // Read an integer from the standard input and store it in temp
		a[temp] = 1 // Set the value of the slice element at index temp to 1
	}

	ansl, ansr := 0, 0 // Declare and initialize two integer variables: ansl and ansr

	for i := x; i <= n; i++ { // Iterate through the range from x to n
		ansr += a[i] // Add the value of the slice element at index i to the variable ansr
	}

	for i := x; i >= 0; i-- { // Iterate through the range from x to 0
		ansl += a[i] // Add the value of the slice element at index i to the variable ansl
	}

	fmt.Println(min(ansl, ansr)) // Print the minimum value between ansl and ansr
}

// min returns the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

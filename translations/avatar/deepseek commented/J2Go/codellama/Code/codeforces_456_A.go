
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n int
	var a, b []int
	var temp, q, w, e int
	var f bool

	// Read the number of elements
	n, _ = strconv.Atoi(os.Args[1])

	// Initialize arrays 'a' and 'b'
	a = make([]int, n)
	b = make([]int, n)

	// Loop through each element
	for i := 0; i < n; i++ {
		// Read the values for arrays 'a' and 'b'
		a[i], _ = strconv.Atoi(os.Args[2*i+2])
		b[i], _ = strconv.Atoi(os.Args[2*i+3])

		// Check if the current 'a' value is greater than the stored 'temp' value
		if temp < a[i] {
			// Check if the stored 'q' value is greater than the current 'b' value
			if q > b[i] {
				f = true // Set 'f' to true if the condition is met
			}
			q = b[i] // Update 'q' with the current 'b' value
			temp = a[i] // Update 'temp' with the current 'a' value
		}

		// Check if the current 'a' value is less than the stored 'temp' value
		if temp > a[i] {
			// Check if the stored 'q' value is less than the current 'b' value
			if q < b[i] {
				f = true // Set 'f' to true if the condition is met
			}
			q = b[i] // Update 'q' with the current 'b' value
			temp = a[i] // Update 'temp' with the current 'a' value
		}

		// Check if the current 'a' value is greater than the stored 'w' value
		if a[i] > w {
			w = a[i] // Update 'w' with the current 'a' value
			if b[i] < e { // Check if the current 'b' value is less than the stored 'e' value
				f = true // Set 'f' to true if the condition is met
			}
			e = b[i] // Update 'e' with the current 'b' value
		}

		// Check if the current 'a' value is less than the stored 'w' value
		if a[i] < w {
			if b[i] > e { // Check if the current 'b' value is greater than the stored 'e' value
				f = true // Set 'f' to true if the condition is met
			}
		}
	}

	// Determine and print the output based on the value of 'f'
	if f == true {
		fmt.Println("Happy Alex") // Print "Happy Alex" if 'f' is true
	} else {
		fmt.Println("Poor Alex") // Print "Poor Alex" if 'f' is false
	}
}


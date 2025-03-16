
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read an integer input which represents the number of elements
	n, _ := strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[0 : len(bufio.NewReader(os.Stdin).ReadLine())-1])

	// Read a list of integers from input and convert them to a list of integers
	number := make([]int, n)
	for i := 0; i < n; i++ {
		number[i], _ = strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[0 : len(bufio.NewReader(os.Stdin).ReadLine())-1])
	}

	// Initialize two variables to hold the sums of the two halves
	h1 := 0 // Sum of the first half
	h2 := 0 // Sum of the second half
	x := 0  // Flag to check if any number is not 4 or 7

	// Iterate through the list of numbers
	for i := 0; i < n; i++ {
		// Check if the current number is neither 4 nor 7
		if number[i]!= 4 && number[i]!= 7 {
			fmt.Println("NO") // Print "NO" if an invalid number is found
			x++              // Increment the flag to indicate an invalid number was found
			break            // Exit the loop since we found an invalid number
		}

		// Sum the first half of the numbers
		if i < n/2 {
			h1 += number[i]
		} else {
			// Sum the second half of the numbers
			h2 += number[i]
		}
	}

	// After checking all numbers, determine if the sums of both halves are equal
	if x == 0 { // Proceed only if no invalid numbers were found
		if h1 == h2 {
			fmt.Println("YES") // Print "YES" if the sums are equal
		} else {
			fmt.Println("NO") // Print "NO" if the sums are not equal
		}
	}
}

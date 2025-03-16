
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the input from the console
	input := strings.Split(fmt.Sprint(os.Stdin), "\n")

	// Get the first integer from the input
	n, _ := strconv.Atoi(input[0])

	// Check if the input is 1, if so, print the only integer and exit the program
	if n == 1 {
		fmt.Println(input[1]) // Print the only integer
		os.Exit(0)            // Exit the program
	}

	// Initialize an array to store the integers
	a := make([]int, n)

	// Read the rest of the integers and add them to the array
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(input[i+1])
	}

	// Sort the array in ascending order
	sort(a)

	// Check if the last integer in the array is 0, if so, print 0 and exit the program
	if a[len(a)-1] == 0 {
		fmt.Println(0) // Print 0
		os.Exit(0)     // Exit the program
	}

	// Initialize the answer variable
	ans := 0

	// Use a while loop to keep applying the function to the array until it contains only one element
	for {
		if len(a) == 1 {
			ans = a[0] // Assign the only remaining integer to the answer variable
			break      // Exit the loop
		}
		a = func(a) // Apply the function to the array and assign the result back to it
	}

	// Print the answer
	fmt.Println(ans)
}

// Define a private function to apply the logic to the array
func func(a []int) []int {
	// Create a copy of the array to modify it without affecting the original one
	b := make([]int, len(a))
	copy(b, a)

	// Initialize the minimum value variable
	min := 0

	// Iterate through the array and apply the logic to each integer
	for i := 0; i < len(b); i++ {
		if b[i] == 0 { // If the current integer is 0, remove it and decrease the index of the for loop
			b = append(b[:i], b[i+1:]...)
			i--
		} else {
			if min != 0 { // If there is already a minimum value, apply the modulo operation and check if the result is 1
				b[i] = b[i] % min
				if b[i] == 1 { // If the result is 1, print 1 and exit the program
					fmt.Println(1)
					os.Exit(0)
				}
			} else { // If there is no minimum value yet, assign the current integer as the minimum value
				min = b[i]
			}
		}
	}

	// Sort the array in ascending order and return it
	sort(b)
	return b
}

// Define a private function to sort the array in ascending order
func sort(a []int) {
	for i := 0; i < len(a); i++ {
		for j := i + 1; j < len(a); j++ {
			if a[i] > a[j] {
				a[i], a[j] = a[j], a[i]
			}
		}
	}
}

// 
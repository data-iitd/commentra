package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a Scanner object to read input from the user
	scanner := bufio.NewScanner(os.Stdin)
	
	// Read the number of elements in the array
	scanner.Scan()
	n, _ := fmt.Sscan(scanner.Text(), &n)
	
	// Initialize an array to hold the input integers
	a := make([]int, n)
	
	// Variable to hold the cumulative XOR of all elements
	var r int
	
	// Read each integer from input and compute the cumulative XOR
	for i := 0; i < n; i++ {
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &a[i])
		r ^= a[i] // Update the cumulative XOR with the current element
	}
	
	// For each element in the array, print the result of XORing the cumulative XOR with the element
	for i := 0; i < n; i++ {
		if i != 0 {
			fmt.Print(" ") // Print a space before the next number if it's not the first element
		}
		fmt.Print(r ^ a[i]) // Print the result of XORing the cumulative XOR with the current element
	}
	fmt.Println() // Print a newline at the end
}

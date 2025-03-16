
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Declare the main function
func main() {
	var n int
	var array [100]int
<<<<<<< HEAD
	var sum int
=======
>>>>>>> 98c87cb78a (data updated)

	// Take the size of the array as input from the user
	fmt.Scanf("%d\n", &n)

	// Initialize the array with user input
	for i := 0; i < n; i++ {
		fmt.Scanf("%d\n", &array[i])
	}

<<<<<<< HEAD
	// Calculate the sum of all the products of distinct pairs of elements in the array
	for i := 0; i < n-1; i++ {
		for j := i + 1; j < n; j++ {
			sum += array[i] * array[j]
=======
	var sum int = 0

	// Calculate the sum of all the products of distinct pairs of elements in the array
	for i := 0; i < n-1; i++ { // Outer loop runs from 0 to n-2
		for j := i + 1; j < n; j++ { // Inner loop runs from i+1 to n
			sum += array[i] * array[j] // Add the product of current and next element to the sum
>>>>>>> 98c87cb78a (data updated)
		}
	}

	// Print the sum of all the products of distinct pairs of elements in the array
	fmt.Printf("%d\n", sum)
}


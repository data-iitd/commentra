

package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	// Declare and initialize variables
	var n, a, sum int
	scanner := bufio.NewScanner(os.Stdin)
	fmt.Fscanf(scanner, "%d\n", &n) // Read the number of elements from the user
	fmt.Fscanf(scanner, "%d\n", &a) // Read the size of the subarray from the user
	s := make([]int, n) // Declare an array of size n to store the input elements

	// Read the elements of the array from the user
	for i := 0; i < n; i++ {
		fmt.Fscanf(scanner, "%d\n", &s[i]) // Read the i-th element of the array
	}

	// Sort the array in ascending order
	sort.Ints(s) // Sort the array using the sort.Ints function from the sort package

	// Calculate the sum of the last 'a' elements of the sorted array
	for i := n - 1; i > n-a-1; i-- {
		sum += s[i] // Add the current element to the sum
	}

	// Print the result
	fmt.Println(sum) // Print the sum of the last 'a' elements
}


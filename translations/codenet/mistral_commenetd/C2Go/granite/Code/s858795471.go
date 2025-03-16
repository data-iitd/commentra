

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function to search for a key in an array
func search(A []int, n int, key int) int {
	i := 0
	// Add the key to the end of the array
	A[n] = key
	// Search for the key in the array using a while loop
	for A[i]!= key {
		i++
	}
	// Return 1 if the key was found before the end of the array, otherwise return 0
	return i!= n
}

func main() {
	var n int // Number of elements in the array
	var A [10000 + 1]int // Array to store the elements
	var q int // Number of queries
	var key int // Key to be searched for
	var sum int // Variable to store the number of keys found
	var i int // Loop counter

	// Read the number of elements in the array from the user
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &n)
	// Read the elements of the array from the user
	for i = 0; i < n; i++ {
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &A[i])
	}
	// Read the number of queries from the user
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &q)
	// For each query, search for the key in the array and if it is found, increment the sum
	for i = 0; i < q; i++ {
		fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &key) // Read the key to be searched for
		// Call the search function to find the key in the array
		if search(A, n, key) { // If the key is found, increment the sum
			sum++
		}
	}
	// Print the number of keys found
	fmt.Println(sum)
}


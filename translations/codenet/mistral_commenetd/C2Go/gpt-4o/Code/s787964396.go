package main

import (
	"fmt"
	"os"
)

const I = 10000

// CountingSort function to perform counting sort algorithm
func CountingSort(a []int, b []int, k int) {
	// Declare an array 'c' of size I to store the count of occurrences of each element
	c := make([]int, I+1)

	// Initialize all elements of array 'c' to zero (not necessary in Go, but for clarity)
	for i := range c {
		c[i] = 0
	}

	// Count the occurrences of each element in array 'a' and store it in array 'c'
	for j := 0; j < k; j++ {
		c[a[j+1]]++
	}

	// Calculate the cumulative sum of all elements in array 'c'
	for i := 1; i < I+1; i++ {
		c[i] += c[i-1]
	}

	// Sort the array 'b' by placing each element 'a[j]' at its correct position in array 'b'
	for j := k; j > 0; j-- {
		b[c[a[j]]] = a[j]
		c[a[j]]--
	}
}

func main() {
	// Declare variables
	var n, max int
	max = 0

	// Read the number of elements 'n' from the user
	fmt.Print("Enter the number of elements: ")
	_, err := fmt.Scan(&n)
	if err != nil {
		fmt.Println("Error reading input:", err)
		os.Exit(1)
	}

	// Allocate memory for slices 'a' and 'b' of size (n+1)
	a := make([]int, n+1)
	b := make([]int, n+1)

	// Read elements of array 'a' from the user
	fmt.Printf("Enter %d integers:\n", n)
	for i := 0; i < n; i++ {
		_, err := fmt.Scan(&a[i+1])
		if err != nil {
			fmt.Println("Error reading input:", err)
			os.Exit(1)
		}
		// Update the maximum element if a new element is greater
		if a[i+1] > max {
			max = a[i+1]
		}
	}

	// Call the CountingSort function to sort the array 'a' using counting sort algorithm
	CountingSort(a, b, n)

	// Print the sorted elements of array 'b'
	fmt.Print(b[1])
	for i := 2; i < n+1; i++ {
		fmt.Printf(" %d", b[i])
	}
	fmt.Println()
}

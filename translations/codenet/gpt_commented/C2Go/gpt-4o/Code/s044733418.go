package main

import (
	"fmt"
	"sort"
)

// Function to sort an array of integers in descending order
type IntSlice []int

func (a IntSlice) Len() int           { return len(a) }
func (a IntSlice) Less(i, j int) bool { return a[i] > a[j] } // Descending order
func (a IntSlice) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }

func main() {
	// Declare an array of integers
	array := make([]int, 10)

	// Read 10 integers from standard input into the array
	for i := 0; i < 10; i++ {
		fmt.Scan(&array[i])
	}

	// Sort the array in descending order
	sort.Sort(IntSlice(array))

	// Print the first 3 elements of the sorted array
	for i := 0; i < 3; i++ {
		fmt.Println(array[i])
	}
}

// <END-OF-CODE>

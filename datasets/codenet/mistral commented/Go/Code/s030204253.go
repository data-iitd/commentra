// Package declaration for the main Go program
package main

// Import the fmt package for formatted I/O operations
import "fmt"

// Initialize an integer variable 'n' and read its value from the standard input
func main() {
	var n int
	fmt.Scan(&n)
}

// Create an array 'a' of 'n' float64 elements
a := make([]float64, n)

// Read 'n' float64 values from the standard input and assign them to the array 'a'
for i := 0; i < n; i++ {
	fmt.Scan(&a[i])
}

// Iterate through the array 'a' 'n-1' times and sort it using the 'Sort.Sort' function
for i := 0; i+1 < n; i++ {
	sort.Sort(sort.Float64Slice(a))
}

// Initialize an empty slice 'na' of float64
na := make([]float64, 0)

// Iterate through the slice 'a' starting from index 2 and append its elements to the slice 'na'
for j := 2; j < len(a); j++ {
	na = append(na, a[j])
}

// Reassign the value of the slice 'a' with the slice 'na' and the first two elements being the average of the first two elements of the original slice 'a'
na = append(na, (a[0]+a[1])/2)
a = na

// Print the first element of the sorted slice 'a' to the standard output
fmt.Println(a[0])

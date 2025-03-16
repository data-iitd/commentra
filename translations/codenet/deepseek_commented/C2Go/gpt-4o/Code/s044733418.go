package main  // Define the main package

import (
    "fmt"  // Import the fmt package for formatted I/O
    "sort" // Import the sort package for sorting
)

// Define a function to compare two integers
type IntSlice []int

func (a IntSlice) Len() int           { return len(a) }
func (a IntSlice) Less(i, j int) bool { return a[j] < a[i] } // Sort in descending order
func (a IntSlice) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }

func main() {  // Define the main function
    array := make([]int, 10)  // Create a slice of 10 integers
    for i := 0; i < 10; i++ { // Read 10 integers from the input
        fmt.Scan(&array[i])
    }
    sort.Sort(IntSlice(array)) // Sort the array using the sort package
    for i := 0; i < 3; i++ {   // Print the first three elements of the sorted array
        fmt.Println(array[i])
    }
}

// <END-OF-CODE>

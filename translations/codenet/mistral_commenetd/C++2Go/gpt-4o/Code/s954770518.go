package main // Declare the main package

import (
    "fmt" // Import the fmt package for formatted I/O
    "sort" // Import the sort package for sorting functionality
)

func main() { // The main function is the entry point of the program
    s := make([]int, 10) // Declare a slice 's' of size 10

    // Read 10 integers from the user and store them in the slice 's'
    for i := 0; i < 10; i++ {
        fmt.Scan(&s[i]) // Read an integer from the standard input and store it in the slice 's' at the current index
    }

    // Sort the slice 's' in ascending order
    sort.Ints(s)

    // Print the 4th, 5th and 6th smallest elements from the sorted slice 's'
    for i := 9; i > 6; i-- { // Initialize the loop counter 'i' to 9 (index of the 5th smallest element) and decrement it until it becomes greater than the index of the 6th smallest element
        fmt.Println(s[i]) // Print the current element of the slice 's' to the standard output
    }
}

// <END-OF-CODE>

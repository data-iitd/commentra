package main

import (
    "fmt"
    "sort"
)

func main() {
    array := make([]int, 10) // Declare a slice of 10 integers

    for i := 0; i < 10; i++ { // Iterate through the slice to read 10 integers
        fmt.Scan(&array[i]) // Read an integer from the user and store it in the slice
    }

    sort.Slice(array, func(i, j int) bool {
        return array[j] < array[i] // Sort in descending order
    })

    for i := 0; i < 3; i++ { // Iterate through the first three elements of the sorted slice
        fmt.Println(array[i]) // Print the first three sorted integers
    }
}

// Return 0 to indicate successful execution of the program
// <END-OF-CODE>

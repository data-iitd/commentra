package main // Declare the main package

import (
    "fmt" // Import the fmt package for formatted I/O
    "sort" // Import the sort package for sorting
)

func main() {
    s := make([]int, 10) // Declare a slice to store the input numbers

    // Step 3: Read input numbers into the slice
    for i := 0; i < 10; i++ {
        fmt.Scan(&s[i]) // Read input and store it in the slice
    }

    // Step 4: Sort the slice
    sort.Ints(s) // Sort the slice in ascending order

    // Step 5: Print the last four numbers of the sorted slice
    for i := 9; i > 5; i-- {
        fmt.Println(s[i]) // Print the last four numbers
    }
}

// <END-OF-CODE>

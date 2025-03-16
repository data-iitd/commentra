package main // Declare the main package

import (
    "fmt" // Import the fmt package for formatted I/O
)

func main() {
    var n, tmp int // Declare number of elements and temporary storage variable
    min := int64(1000000) // Initialize min
    max := int64(-1000000) // Initialize max
    sum := int64(0) // Initialize sum

    fmt.Scan(&n) // Read the number of elements

    for i := 0; i < n; i++ { // Loop through the number of elements
        fmt.Scan(&tmp) // Read an integer value into tmp
        if min > int64(tmp) { // Update min if tmp is smaller
            min = int64(tmp)
        }
        if max < int64(tmp) { // Update max if tmp is larger
            max = int64(tmp)
        }
        sum += int64(tmp) // Add tmp to sum
    }

    fmt.Printf("%d %d %d\n", min, max, sum) // Print the results
}

// <END-OF-CODE>

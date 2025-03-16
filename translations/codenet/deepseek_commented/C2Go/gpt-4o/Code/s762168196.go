package main  // Step 1: Define the main package

import (
    "fmt"  // Step 1: Import necessary packages
)

func main() {  // Step 1: Define the main function

    // Step 2: Declare necessary variables
    var n int
    var sum int64 = 0
    var a [10000]int
    var min, max int

    // Step 3: Read the number of elements (n) from the user
    fmt.Scan(&n)

    // Step 4: Read the elements of the array from the user and calculate the sum
    for i := 0; i < n; i++ {
        fmt.Scan(&a[i])
        sum += int64(a[i])
    }

    // Step 5: Find the minimum and maximum values in the array
    max = a[0]
    min = a[0]
    for i := 1; i < n; i++ {
        if a[i] > max {
            max = a[i]
        }
        if a[i] < min {
            min = a[i]
        }
    }

    // Step 6: Print the minimum, maximum, and sum of the elements
    fmt.Printf("%d %d %d\n", min, max, sum)

}  // End of the main function
// <END-OF-CODE>

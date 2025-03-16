package main // Declare the main package

import (
    "fmt" // Import the fmt package for input/output operations
    "sort" // Import the sort package for sorting slices
)

func main() {
    var n, k int // Declare two integer variables, n and k

    fmt.Scan(&n, &k) // Read the number of elements and the size of the subarray from the user

    l := make([]int, n) // Create a slice l of size n

    for i := 0; i < n; i++ { // Iterate through the elements of the slice l
        fmt.Scan(&l[i]) // Read each element from the user
    }

    sort.Ints(l) // Sort the slice l in ascending order

    ans := 0 // Initialize an integer variable ans to 0 for storing the sum of the first k elements in descending order

    for i := 0; i < k; i++ { // Iterate through the last k elements in descending order
        ans += l[n-1-i] // Add their values to the variable ans
    }

    fmt.Println(ans) // Output the value of the variable ans to the console
}

// <END-OF-CODE>

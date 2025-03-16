package main // Declare the main package

import (
    "fmt" // Import the fmt package for formatted I/O
)

func main() { // Declare the main function
    var n, k int // Declare two integer variables n and k
    const size = 99999 // Define a constant for the size of the array
    p := make([]int, size) // Create a slice p of integers with a size of 99999
    var o int // Declare an integer variable o and initialize it to 0

    fmt.Scanf("%d %d", &n, &k) // Read two integers from the standard input and store them in variables n and k

    for i := 0; i < n; i++ { // Iterate through the slice p from index 0 to n-1
        fmt.Scanf("%d", &p[i]) // Read an integer from the standard input and store it in the slice p at index i
    }

    for i := 0; i < n; i++ { // Iterate through the slice p from index 0 to n-1
        l := i // Initialize variable l to i
        for j := i + 1; j < n; j++ { // Iterate through the slice p from index i+1 to n-1
            if p[j] < p[l] { // If the element at index j is smaller than the element at index l
                l = j // Update the index of the smallest element
            }
        }
        if l != i { // If the index of the smallest element is not equal to i
            // Swap the elements at indices i and l
            p[i], p[l] = p[l], p[i]
        }
    }

    for i := 0; i < k; i++ { // Iterate through the slice p from index 0 to k-1
        o += p[i] // Add the element at index i to the variable o
    }

    fmt.Println(o) // Print the value of the variable o to the standard output
}

// <END-OF-CODE>

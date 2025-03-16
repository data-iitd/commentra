
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare variables
    var n int // Number of elements in the array
    var avg float64 // Average of the elements in the array
    var s float64 // Difference between the first element and the average
    var ans int // Index of the element with the maximum difference from the average

    // Initialize variables
    reader := bufio.NewReader(os.Stdin) // Create a new reader for the standard input
    fmt.Fscanf(reader, "%d\n", &n) // Read the number of elements from the standard input
    a := make([]int, n) // Declare and initialize an array of size n with zeros

    // Calculate the average of the elements in the array
    for i := 0; i < n; i++ {
        fmt.Fscanf(reader, "%d\n", &a[i]) // Read an element from the standard input and store it in the array
        avg += float64(a[i]) // Add the current element to the sum of all elements
    }

    // Calculate the average and divide it by the number of elements
    avg /= float64(n)

    // Initialize the difference between the first element and the average
    s = float64(abs(a[0] - int(avg)))

    // Initialize the index of the element with the maximum difference from the average
    ans = 0

    // Find the index of the element with the maximum difference from the average
    for i := 1; i < n; i++ {
        if s > float64(abs(a[i] - int(avg))) { // If the current difference is greater than the previous difference
            s = float64(abs(a[i] - int(avg))) // Update the difference
            ans = i // Update the index
        }
    }

    // Print the index of the element with the maximum difference from the average
    fmt.Println(ans) // Print the index of the element with the maximum difference from the average

    // Terminate the program
    return
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}


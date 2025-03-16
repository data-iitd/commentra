

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    N, _ := strconv.Atoi(reader.ReadLine()) // Read the number of elements from the standard input

    A := make([]int, N) // Declare and initialize an array of size N
    for i := 0; i < N; i++ {
        A[i], _ = strconv.Atoi(reader.ReadLine()) // Read each element of the array from the standard input
    }

    minElement := A[0] // Initialize minimum element variable with first element
    maxElement := A[0] // Initialize maximum element variable with first element

    // Find minimum and maximum elements in the array
    for i := 0; i < N; i++ {
        if A[i] < minElement { // If current element is smaller than the current minimum
            minElement = A[i] // Update minimum element
        }
        if A[i] > maxElement { // If current element is larger than the current maximum
            maxElement = A[i] // Update maximum element
        }
    }

    // Print the difference between maximum and minimum elements
    fmt.Println("Difference between maximum and minimum elements:", maxElement-minElement)
}


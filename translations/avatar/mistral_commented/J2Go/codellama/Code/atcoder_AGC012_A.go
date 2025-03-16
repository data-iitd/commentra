
package main

import (
    "fmt"
    "math"
    "os"
    "strconv"
)

func main() {
    // Reading the number of elements in the array from the standard input
    n, _ := strconv.Atoi(os.Args[1])

    // Creating an integer array of size 3 times the number of elements
    array := make([]int, 3*n)

    // Initializing the array with input values
    for i := 0; i < len(array); i++ {
        array[i], _ = strconv.Atoi(os.Args[i+2])
    }

    // Sorting the array in ascending order
    sort.Ints(array)

    head := len(array) - 2 // Index of the last element to be considered in the current iteration
    res := 0               // Result variable to store the sum of the last two elements in each subarray

    // Calculating the sum of the last two elements in each subarray of size n and adding it to the result
    for i := 0; i < n; i++ {
        res += array[head] // Adding the last element of the current subarray to the result
        head -= 2          // Decreasing the index of the last element by 2 to consider the next subarray
    }

    // Printing the result
    fmt.Println(res)
}



package main

import "fmt"

func main() {
    // Initialize an empty list `L`
    L := []int{}

    // Read the first input, which is the number of elements to add to the list
    fmt.Scanln(&n)

    // Use a for loop to iterate through each integer in the input
    for i := 0; i < n; i++ {
        // Add `r` elements to the list `L` with the value `r`
        for j := 0; j < r; j++ {
            L = append(L, r)
        }
        // Increment the value of `r` by 1 to prepare for the next iteration
        r++
    }

    // Read the second input, which represents the indices of the elements to print from the list
    fmt.Scanln(&n)

    // Use another for loop to iterate through each integer in the input
    for i := 0; i < n; i++ {
        // Print the element at the given index using the index as an offset from the beginning of the list
        fmt.Println(L[i])
    }
}


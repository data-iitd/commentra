package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

func main() {
    // Declare variables for the number of elements (N) and the number of operations (M)
    var N, M int
    fmt.Scanf("%d %d\n", &N, &M)

    // Initialize a vector to hold the elements, with a size of 100000
    L := make([]int, 100000)
    var l int

    // Read N integers from input and store them in the vector L
    for i := 0; i < N; i++ {
        fmt.Scanf("%d\n", &l)
        L[i] = l
    }

    // Sort the vector L in ascending order
    sort.Ints(L)

    // Declare an iterator for the vector
    itr := 0

    // Perform M operations to modify the vector L
    for i := 0; i < M; i++ {
        // Get the maximum element from the end of the sorted vector
        max_L := L[len(L)-1]

        // If the maximum element is 0, break the loop as no further operations are needed
        if max_L == 0 {
            break
        }

        // Halve the maximum element
        max_L /= 2

        // Find the position to insert the halved value in the sorted vector
        for itr = 0; itr < len(L); itr++ {
            if L[itr] >= max_L {
                break
            }
        }

        // Insert the halved value into the vector at the found position
        L = append(L[:itr], append([]int{max_L}, L[itr:]...)...)

        // Remove the last element (the original maximum) from the vector
        L = L[:len(L)-1]
    }

    // Calculate the sum of all elements in the vector L
    ans := 0
    for _, l := range L {
        ans += l
    }

    // Output the final sum
    fmt.Println(ans)
}


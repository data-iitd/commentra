

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main ( ) {
    var L [ ] int
    var r int = 1
    var n int
    var m int
    var j int
    var k int
    var err error

    // Initialize an empty slice `L`
    L = [ ] int { }

    // Read the first input, which is the number of elements to add to the list
    fmt.Scan ( & n )

    // Use a for loop to iterate through each integer in the input
    for k = 0 ; k < n ; k ++ {
        // Read the next integer from the input
        fmt.Scan ( & m )
        // Add `m` elements to the slice `L` with the value `r`
        L = append ( L, make ( [ ] int, m )... )
        for j = 0 ; j < m ; j ++ {
            L [ k * m + j ] = r
        }
        // Increment the value of `r` by 1 to prepare for the next iteration
        r += 1
    }

    // Read the second input, which represents the indices of the elements to print from the list
    fmt.Scan ( & n )

    // Use another for loop to iterate through each integer in the input
    for k = 0 ; k < n ; k ++ {
        // Read the next integer from the input
        fmt.Scan ( & m )
        // Print the element at the given index using the index as an offset from the beginning of the list
        fmt.Println ( L [ m - 1 ] )
    }
}


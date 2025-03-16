
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "math"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Initialize minimum value of array A to a large number
<<<<<<< HEAD
    minA := math.MaxInt32
=======
    minA := math.MaxInt64
>>>>>>> 98c87cb78a (data updated)
    num := 0

    // Read number of elements and time t from the standard input
    n, t := 0, 0
    fmt.Scanf("%d %d", &n, &t)

    // Create a vector A of size n to store the input elements
    A := make([]int, n)

    // Read each element of vector A from the standard input
    for i := 0; i < n; i++ {
        fmt.Scanf("%d", &A[i])
        // Check if the current element is smaller than the minimum value
        if minA > A[i] {
            // Update the minimum value of array A
            minA = A[i]
        } else {
            // Calculate the difference between the current element and the minimum value
            diff := A[i] - minA

            // If the difference is equal to the previous difference, increment the count of similar differences
            if f == diff {
                num++
            }
            // If the difference is greater than the previous difference, reset the count to 1 and update the previous difference
            else if f < diff {
                num = 1
                f = diff
            }
        }
    }

    // Print the count of similar differences on the standard output
    fmt.Println(num)
}


<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "math"
)

func main() {
    // Initialize the minimum value to a large number
    minA := math.MaxInt32
    // Initialize the number of ways to achieve the maximum profit
    num := 0
    // Read the number of elements and an unused variable 't'
    var n, t int
<<<<<<< HEAD
    fmt.Scanf("%d %d", &n, &t)
=======
    fmt.Scanf("%d %d\n", &n, &t)
>>>>>>> 98c87cb78a (data updated)
    // Create a vector to store the elements
    A := make([]int, n)
    // Read the elements into the vector
    for i := 0; i < n; i++ {
<<<<<<< HEAD
        fmt.Scanf("%d", &A[i])
=======
        fmt.Scanf("%d\n", &A[i])
>>>>>>> 98c87cb78a (data updated)
    }
    // Iterate through the vector to find the maximum profit
    for i := 0; i < n; i++ {
        // Update the minimum value found so far
        if minA > A[i] {
            minA = A[i]
        } else {
            // Check if the current profit is equal to the maximum profit found so far
            if f == A[i]-minA {
                num++
            } else if f < A[i]-minA {
                // Update the maximum profit and reset the count if a new maximum is found
                num = 1
                f = A[i] - minA
            }
        }
    }
    // Output the number of ways to achieve the maximum profit
<<<<<<< HEAD
    fmt.Println(num)
=======
    fmt.Printf("%d\n", num)
>>>>>>> 98c87cb78a (data updated)
}


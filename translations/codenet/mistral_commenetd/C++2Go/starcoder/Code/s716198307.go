<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// The main function from where the execution begins
func main() {
    // Declare variables
    var n int
    var avg float64
    var s float64
    var ans int

    // Initialize variables
<<<<<<< HEAD
    fmt.Scanln(&n) // Read the number of elements from the standard input
    a := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scanln(&a[i]) // Read an element from the standard input and store it in the array
=======
    fmt.Scanln(&n)
    a := make([]int, 100)
    for i := 0; i < n; i++ {
        fmt.Scanln(&a[i])
>>>>>>> 98c87cb78a (data updated)
        avg += float64(a[i])
    }
    avg /= float64(n)

    // Initialize the difference between the first element and the average
<<<<<<< HEAD
    s = float64(math.Abs(a[0] - avg))
=======
    s = float64(abs(a[0] - avg))
>>>>>>> 98c87cb78a (data updated)

    // Initialize the index of the element with the maximum difference from the average
    ans = 0

    // Find the index of the element with the maximum difference from the average
    for i := 1; i < n; i++ {
<<<<<<< HEAD
        if s > float64(math.Abs(a[i] - avg)) {
            s = float64(math.Abs(a[i] - avg))
=======
        if s > float64(abs(a[i] - avg)) {
            s = float64(abs(a[i] - avg))
>>>>>>> 98c87cb78a (data updated)
            ans = i
        }
    }

    // Print the index of the element with the maximum difference from the average
    fmt.Println(ans)
}


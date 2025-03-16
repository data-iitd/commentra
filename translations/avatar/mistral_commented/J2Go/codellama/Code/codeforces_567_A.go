
package main

import (
    "fmt"
    "math"
    "os"
    "strconv"
)

func main() {
    // Asking user for the size of the array and initializing it
    fmt.Print("Enter the size of the array: ")
    var a int
    fmt.Scan(&a)
    ar := make([]int, a)

    // Initializing variables for storing maximum and minimum differences
    var max, min int

    // Reading array elements from user input
    for i := 0; i < a; i++ {
        fmt.Print("Enter the value of the array: ")
        var value int
        fmt.Scan(&value)
        ar[i] = value
    }

    // Finding maximum and minimum differences between consecutive elements in the array
    for i := 0; i < a; i++ {
        // Finding maximum difference between current element and first element
        max = int(math.Max(float64(ar[i]-ar[0]), float64(ar[a-1]-ar[i])))

        // Finding minimum difference between current element and previous element
        if i == 0 {
            min = ar[i+1] - ar[i] // For the first element, minimum difference is between current and next element
        } else if i == a-1 {
            min = ar[i] - ar[i-1] // For the last element, minimum difference is between current and previous element
        } else {
            min = int(math.Min(float64(ar[i]-ar[i-1]), float64(ar[i+1]-ar[i]))) // For other elements, minimum difference is between current and previous or next element, whichever is smaller
        }

        // Printing minimum and maximum differences for each pair of consecutive elements
        fmt.Println(min, max)
    }
}


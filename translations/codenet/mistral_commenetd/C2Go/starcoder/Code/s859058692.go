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

func main() {
    var sum int64 = 0
    var m, n, i, min, max int
    var input string

    // Read the number of integers to be input from the user
    fmt.Scanf("%d\n", &n)

    // Iterate through each integer input
    for i = 0; i < n; i++ {
        fmt.Scanf("%d", &m) // Read an integer input and assign it to m
        sum += m // Add the current integer input to the sum

        // Update min and max values if the current input is smaller or larger
        if min > m {
            min = m // Set min to the current input if it's smaller
        }
        if max < m {
            max = m // Set max to the current input if it's larger
        }
    }

    // Print the minimum value, maximum value, and sum of the input integers
    fmt.Printf("%d %d %d\n", min, max, sum)
}


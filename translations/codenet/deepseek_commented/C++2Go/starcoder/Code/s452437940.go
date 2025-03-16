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

<<<<<<< HEAD
// Main function is the entry point of the program
=======
>>>>>>> 98c87cb78a (data updated)
func main() {
    // Declare variables to store user input
    var a, b, x int64

    // Read three long long integers from standard input
<<<<<<< HEAD
    fmt.Scanf("%d %d %d", &a, &b, &x)
=======
    fmt.Scanf("%d%d%d", &a, &b, &x)
>>>>>>> 98c87cb78a (data updated)

    // Calculate the number of multiples of x between a and b inclusive
    s := (b / x - a / x)

    // Check if a is a multiple of x and adjust the count accordingly
    if a%x == 0 {
        s++
    }

    // Print the result
    fmt.Printf("%d\n", s)
}


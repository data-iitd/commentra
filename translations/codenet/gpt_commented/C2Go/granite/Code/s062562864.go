
package main

import "fmt"

func main() {
    // Declare integer variables to hold input values and results
    var a, b, c, d, i, j int

    // Read four integers from user input
    fmt.Scan(&a, &b, &c, &d)

    // Calculate the product of the first two integers
    i = a * b

    // Calculate the product of the last two integers
    j = c * d

    // Compare the two products and print the larger one
    if i > j {
        // If the first product is greater, print it
        fmt.Println(i)
    } else {
        // Otherwise, print the second product
        fmt.Println(j)
    }
}

// END-OF-CODE
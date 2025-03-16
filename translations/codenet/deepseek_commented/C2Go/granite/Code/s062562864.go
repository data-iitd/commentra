
package main

import "fmt"

func main() {
    var a, b, c, d, i, j int

    // Read four integers from the user
    fmt.Scan(&a, &b, &c, &d)

    // Perform multiplication operations and store the results in i and j
    i = a * b
    j = c * d

    // Use an if-else statement to compare the results and print the larger one
    if i > j {
        fmt.Println(i)
    } else {
        fmt.Println(j)
    }
}

// END-OF-CODE
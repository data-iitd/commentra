
package main

import "fmt"

func main() {
    // Declare variables to hold input values
    var N, A int

    // Read an integer value for N from standard input
    fmt.Scan(&N)

    // Read an integer value for A from standard input
    fmt.Scan(&A)

    // Calculate the result by squaring N and subtracting A, then output the result
    fmt.Println(N * N - A)
}


package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare variables to hold input values
    var N, A int

    // Read an integer value for N from standard input
    fmt.Scanln(&N)

    // Read an integer value for A from standard input
    fmt.Scanln(&A)

    // Calculate the result by squaring N and subtracting A, then output the result
    fmt.Println(N*N - A)
}


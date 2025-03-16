package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare variables to hold input values and results
    var a, b, c, d, e, max int

    // Read two integers from user input
    fmt.Scanf("%d %d", &a, &b)

    // Calculate the sum, difference, and product of A and B
    c = a + b // Sum of A and B
    d = a - b // Difference of A and B
    e = a * b // Product of A and B

    // Initialize max with the value of C (sum)
    max = c

    // Compare max with D (difference) and update if D is greater
    if max < d {
        max = d
    }

    // Compare max with E (product) and update if E is greater
    if max < e {
        max = e
    }

    // Print the maximum value among sum, difference, and product
    fmt.Println(max)
}


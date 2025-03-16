
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Declare variables
    var n, x, min, m, i int

    // Create a new scanner to read input from the standard input
    scanner := bufio.NewScanner(os.Stdin)

    // Read the number of elements (n), a value (x), and the initial minimum value (min)
    scanner.Scan()
    n, _ = strconv.Atoi(scanner.Text())
    scanner.Scan()
    x, _ = strconv.Atoi(scanner.Text())
    scanner.Scan()
    min, _ = strconv.Atoi(scanner.Text())

    // Adjust x by subtracting the initial minimum value
    x -= min

    // Loop through the remaining n-1 elements to read their values
    for i = 1; i < n; i++ {
        // Read the next element into variable m
        scanner.Scan()
        m, _ = strconv.Atoi(scanner.Text())

        // Subtract the current element from x
        x -= m

        // Update min if the current element is smaller than the current minimum
        if min > m {
            min = m
        }
    }

    // Calculate and print the result based on the number of elements and the adjusted x divided by the minimum value
    fmt.Println(n + x/min)
}


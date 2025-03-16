
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Create a new scanner to read input from standard input
    scanner := bufio.NewScanner(os.Stdin)

    // Read two integers from standard input
    // n represents the number of rows, and m represents the number of columns
    scanner.Scan()
    line := scanner.Text()
    parts := strings.Split(line, " ")
    n, _ := strconv.Atoi(parts[0])
    m, _ := strconv.Atoi(parts[1])

    // Calculate the product of (n - 1) and (m - 1)
    // This represents the number of internal edges in a grid of n by m cells
    result := (n - 1) * (m - 1)

    // Print the result to standard output
    fmt.Println(result)

    // Flush the output buffer to ensure all output is printed
    fmt.Println()
}


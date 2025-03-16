
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Initialize bufio.Scanner object to read input from standard input
    scanner := bufio.NewScanner(os.Stdin)

    // Read first integer input A from user
    scanner.Scan()
    A, _ := strconv.Atoi(scanner.Text())

    // Read second integer input B from user
    scanner.Scan()
    B, _ := strconv.Atoi(scanner.Text())

    // Initialize variables for storing remainders and result
    var amari int
    var result int

    // Calculate the result by dividing B by A - 1 and storing the quotient
    result = (B - 1) / (A - 1)

    // Calculate the remainder of B divided by A - 1 and store it in amari
    amari = (B - 1) % (A - 1)

    // Check if the remainder is not zero
    if amari!= 0 {
        // If the remainder is not zero, increment the result by 1
        result += 1
    }

    // Initialize bufio.Writer object to write output to standard output
    writer := bufio.NewWriter(os.Stdout)

    // Write the result to the standard output
    fmt.Fprintf(writer, "%d\n", result)

    // Flush the bufio.Writer buffer to write the output immediately
    writer.Flush()
}


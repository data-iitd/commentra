

package main

import (
    "bufio"
    "fmt"
    "math/big"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Initialize bufio.Scanner to read input from the user
    scanner := bufio.NewScanner(os.Stdin)

    // Read three string values: N, d, and x
    scanner.Scan()
    N, _ := strconv.ParseFloat(scanner.Text(), 64)
    scanner.Scan()
    d, _ := strconv.ParseFloat(scanner.Text(), 64)
    scanner.Scan()
    x, _ := strconv.ParseFloat(scanner.Text(), 64)

    // Initialize big.Float to store the result with precision
    ans := big.NewFloat(0)

    // Continue the loop until N is greater than 0.5
    for N > 0.5 {
        // Calculate a value using big.Float for precision
        adnum := big.NewFloat(d + x*(N-0.5))
        ans = ans.Add(ans, adnum)

        // Update the values of d and x based on the current value of N
        d = (N+1.0)*d/N + (5.0*x)/(2.0*N)
        x = (1.0+(2.0/N))*x

        // Decrement N by 1 in each iteration
        N--
    }

    // Print the result formatted to a specific number of decimal places
    fmt.Println(ans)
}


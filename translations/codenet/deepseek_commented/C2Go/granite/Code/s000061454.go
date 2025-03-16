
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Variable declarations
    var a, b, n int // Input values and loop counters
    var sum int // To store the sum of the digits
    var i, j int // Loop counters

    // Infinite loop
    for {
        // Read three integers from standard input
        input := bufio.NewScanner(os.Stdin)
        if!input.Scan() {
            break // Break if input reading fails
        }
        line := input.Text()
        parts := strings.Split(line, " ")
        a, _ = strconv.Atoi(parts[0])
        b, _ = strconv.Atoi(parts[1])
        n, _ = strconv.Atoi(parts[2])

        // Reduce 'a' to its remainder when divided by 'b'
        a -= a / b * b

        // Initialize sum to zero
        sum = 0

        // Outer loop runs 'n' times
        for i = 1; i <= n; i++ {
            // Multiply 'a' by 10 to shift the decimal point
            a *= 10

            // Inner loop iterates from 9 down to 0
            for j = 9; j >= 0; j-- {
                // Find the largest digit 'j' such that 'b*j' is less than or equal to 'a'
                if b*j <= a {
                    break
                }
            }

            // Subtract 'b*j' from 'a' and add 'j' to the sum
            a -= b * j
            sum += j
        }

        // Output the sum of the digits
        fmt.Println(sum)
    }
}


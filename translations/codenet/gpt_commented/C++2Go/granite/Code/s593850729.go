
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Declare variables to hold the maximum counts of each denomination and the target amount
    var A, B, C, X int

    // Read input values for the maximum counts of 500, 100, 50 yen coins and the target amount
    scanner := bufio.NewScanner(os.Stdin)
    if scanner.Scan() {
        A, _ = strconv.Atoi(scanner.Text())
    }
    if scanner.Scan() {
        B, _ = strconv.Atoi(scanner.Text())
    }
    if scanner.Scan() {
        C, _ = strconv.Atoi(scanner.Text())
    }
    if scanner.Scan() {
        X, _ = strconv.Atoi(scanner.Text())
    }

    // Initialize a counter to keep track of the number of combinations that sum to X
    cnt := 0

    // Iterate through all possible counts of 500 yen coins (from 0 to A)
    for a := 0; a <= A; a++ {
        // Iterate through all possible counts of 100 yen coins (from 0 to B)
        for b := 0; b <= B; b++ {
            // Iterate through all possible counts of 50 yen coins (from 0 to C)
            for c := 0; c <= C; c++ {
                // Calculate the total amount using the current counts of coins
                total := 500 * a + 100 * b + 50 * c

                // Check if the calculated total matches the target amount X
                if total == X {
                    // If it matches, increment the counter
                    cnt++
                }
            }
        }
    }

    // Output the total number of combinations that sum to X
    fmt.Println(cnt)
}


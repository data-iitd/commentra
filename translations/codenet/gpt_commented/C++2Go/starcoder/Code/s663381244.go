package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Disable synchronization with C I/O for faster input/output
    bufio.NewReader(os.Stdin).ReadRune()

    // Initialize a slice to hold the denominations of money
    m := []int{10, 50, 100, 500}

    var first bool = true // Flag to handle formatting of output
    // Read money input until EOF or invalid input
    for {
        var money int
        _, err := fmt.Scanf("%d", &money)
        if err!= nil {
            break
        }

        // Print a newline before the output of subsequent transactions
        if!first {
            fmt.Println()
        }
        first = false

        var sum int = 0 // Initialize sum to calculate total value of coins
        var num [4]int // Array to hold the number of each denomination

        // Read the number of coins for each denomination and calculate the total sum
        for i := 0; i < 4; i++ {
            fmt.Scanf("%d", &num[i])
            sum += num[i] * m[i]
        }

        // Calculate the change to be returned
        var change int = sum - money

        // Calculate how many coins of each denomination to return as change
        for i := 3; i >= 0; i-- {
            if change/m[i] > 0 {
                num[i] -= change / m[i]
                change %= m[i]
            }
        }

        // Output the remaining coins of each denomination that are greater than zero
        for i := 0; i < 4; i++ {
            if num[i] > 0 {
                fmt.Printf("%d %d\n", m[i], num[i])
            }
        }
    }
}



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
    in := bufio.NewReader(os.Stdin)
    out := bufio.NewWriter(os.Stdout)

    // Initialize a slice to hold the denominations of money
    m := []int{10, 50, 100, 500}

    first := true // Flag to handle formatting of output
    // Read money input until EOF or invalid input
    for {
        // Read the next line of input
        line, _, err := in.ReadLine()
        if err!= nil {
            break // Exit the loop if an error occurs or EOF is reached
        }

        // Print a newline before the output of subsequent transactions
        if!first {
            fmt.Fprintln(out)
        }

        first = false // Set the flag to false after the first input
        sum := 0       // Initialize sum to calculate total value of coins
        num := []int{0, 0, 0, 0} // Slice to hold the number of each denomination

        // Split the input line into individual words
        words := strings.Fields(string(line))
        money, err := strconv.Atoi(words[0])
        if err!= nil {
            continue // Skip the current input if it is invalid
        }

        sum = money // Set the initial sum to the input money value

        // Read the number of coins for each denomination and calculate the total sum
        for i := 0; i < 4; i++ {
            num[i], err = strconv.Atoi(words[i+1])
            if err!= nil {
                continue // Skip the current input if it is invalid
            }
            sum += num[i] * m[i] // Update the total sum
        }

        // Calculate the change to be returned
        change := sum - money

        // Calculate how many coins of each denomination to return as change
        for i := 3; i >= 0; i-- {
            if change >= m[i] { // Check if the current denomination can be used for change
                num[i] = num[i] - change/m[i] // Reduce the number of coins of this denomination
                change = change % m[i] // Update the remaining change to be returned
            }
        }

        // Output the remaining coins of each denomination that are greater than zero
        for i := 0; i < 4; i++ {
            if num[i] > 0 { // Only print denominations that still have coins left
                fmt.Fprintf(out, "%d %d\n", m[i], num[i]) // Print denomination and count
            }
        }
    }

    // Flush the output buffer
    out.Flush()
}


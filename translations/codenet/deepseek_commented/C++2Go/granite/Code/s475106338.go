
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Declare variables to store loop index, transaction type, and number of items
    var i, t, n int

    // Create a scanner to read input from standard input
    scanner := bufio.NewScanner(os.Stdin)

    // Loop through four transactions
    for i = 0; i < 4; i++ {
        // Read the transaction type and number of items from standard input
        scanner.Scan()
        t, _ = strconv.Atoi(scanner.Text())
        scanner.Scan()
        n, _ = strconv.Atoi(scanner.Text())

        // Check the transaction type and calculate the total cost
        if t == 1 {
            fmt.Println(6000 * n) // If transaction type is 1, calculate cost for 6000 per item
        } else if t == 2 {
            fmt.Println(4000 * n) // If transaction type is 2, calculate cost for 4000 per item
        } else if t == 3 {
            fmt.Println(3000 * n) // If transaction type is 3, calculate cost for 3000 per item
        } else if t == 4 {
            fmt.Println(2000 * n) // If transaction type is 4, calculate cost for 2000 per item
        }
    }
}


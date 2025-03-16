

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Create a new scanner to read input from the user
    scanner := bufio.NewScanner(os.Stdin)

    // Read two integers from the input
    scanner.Scan()
    a, _ := strconv.Atoi(scanner.Text())
    scanner.Scan()
    b, _ := strconv.Atoi(scanner.Text())

    // Initialize sum to 0, this will store the sum of the two numbers
    sum := 0

    // Loop runs twice, each time adding the larger of the two numbers to sum
    // and decrementing that number by 1
    for i := 0; i < 2; i++ {
        if a >= b {
            sum += a
            a = a - 1
        } else {
            sum += b
            b = b - 1
        }
    }

    // Print the final sum to the console
    fmt.Println(sum)
}


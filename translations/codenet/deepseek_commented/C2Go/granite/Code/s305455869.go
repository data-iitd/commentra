
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Declare integer variables to store user input and the result
    var a, b int
    var ans int

    // Create a new scanner to read input from the user
    scanner := bufio.NewScanner(os.Stdin)

    // Read two integers from the user
    if scanner.Scan() {
        a, _ = strconv.Atoi(scanner.Text())
    }
    if scanner.Scan() {
        b, _ = strconv.Atoi(scanner.Text())
    }

    // Initialize the result variable to 0
    ans = 0

    // Check the value of 'a' and update 'ans' accordingly
    if a >= 13 {
        // If 'a' is 13 or greater, set 'ans' to 'b'
        ans = b
    } else if a >= 6 {
        // If 'a' is between 6 and 12 (inclusive), set 'ans' to half of 'b'
        ans = b / 2
    }

    // Print the result
    fmt.Println(ans)
}



package main

import (
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Initializing the Scanner object to read input from the standard input stream
    sc := bufio.NewScanner(os.Stdin)

    var n int // Declaring an integer variable to store the first number

    // Reading the first number from the user input
    sc.Scan()
    n, _ = strconv.Atoi(sc.Text())

    fmt.Println(n, " ") // Printing the first number to the standard output stream

    m := n // Initializing an integer variable 'm' with the value of 'n'

    // Finding the factors of the number 'n' using a for loop
    for i := n - 1; i > 0; i-- {
        if m%i == 0 { // Checking if 'i' is a factor of 'm'
            fmt.Println(i, " ") // Printing the factor to the standard output stream
            m = i               // Updating the value of 'm' with the current factor
        }
    }
}


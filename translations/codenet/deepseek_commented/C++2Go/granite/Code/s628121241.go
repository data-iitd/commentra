
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

    // Take an integer input from the user
    scanner.Scan()
    R, _ := strconv.Atoi(scanner.Text())

    // Check the value of R and print the corresponding output
    if R < 1200 {
        fmt.Println("ABC") // If R is less than 1200, print "ABC"
    } else if R >= 2800 {
        fmt.Println("AGC") // If R is 2800 or more, print "AGC"
    } else {
        fmt.Println("ARC") // Otherwise, print "ARC"
    }
}


package main

import (
    "fmt"
    "os"
    "strconv"
)

func main() {
    var str string
    var k int64
    var n int

    // Reading the first line of input as a String
    fmt.Scan(&str)

    // Converting the String to a character array
    c := []rune(str)

    // Reading the second line of input as a long integer
    fmt.Scan(&k)

    // Finding the length of the String
    n = len(str)

    for i := 0; i < int(k); i++ {
        // Checking if the current character is '1'
        if c[i] == '1' {
            // Checking if the current index is the last index of the array
            if i == int(k)-1 {
                // If yes, print '1' and exit the method
                fmt.Println(1)
                return
            }
        } else {
            // If the current character is not '1', print it to the console
            fmt.Println(string(c[i]))
            // Exit the method as soon as a non-'1' character is found
            return
        }
    }
}


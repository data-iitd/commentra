package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Creating a new scanner to read input from the user
    sc := bufio.NewScanner(os.Stdin)

    // Reading two integers n and k from user input
    fmt.Println("Enter n and k")
    fmt.Scanln(&n, &k)

    // Reading a string a from user input
    fmt.Println("Enter a")
    fmt.Scanln(&a)

    // Check if k is greater than half of n
    if k > n/2 {
        // If true, move to the right until k equals n
        for i := 0; i < n-k; i++ {
            fmt.Println("RIGHT")
        }
    } else {
        // If false, move to the left until k equals 1
        for i := 0; i < k-1; i++ {
            fmt.Println("LEFT")
        }
    }

    // If k equals 1, print the characters of the string from left to right
    if k == 1 {
        for i := 0; i < len(a); i++ {
            fmt.Println("PRINT " + a[i])
            // If not at the last character, output "RIGHT"
            if i < len(a)-1 {
                fmt.Println("RIGHT")
            }
        }
    } else {
        // If k is not 1, print the characters of the string from right to left
        for i := len(a) - 1; i >= 0; i-- {
            fmt.Println("PRINT " + a[i])
            // If not at the first character, output "LEFT"
            if i > 0 {
                fmt.Println("LEFT")
            }
        }
    }
}


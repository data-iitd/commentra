package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare three integer variables to hold the input values
    var a, b, c int

    // Read three integers from the user input
    fmt.Scanf("%d %d %d\n", &a, &b, &c)

    // Check if the number formed by a, b, and c is divisible by 4
    // The number is formed as 100*a + 10*b + c
    if ((100 * a + 10 * b + c) % 4 == 0) {
        // If the number is divisible by 4, output "YES"
        fmt.Println("YES")
    } else {
        // If the number is not divisible by 4, output "NO"
        fmt.Println("NO")
    }
}


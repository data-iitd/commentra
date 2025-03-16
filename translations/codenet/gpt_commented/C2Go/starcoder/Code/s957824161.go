package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Read two integers from user input
    x, _ := strconv.Atoi(strings.TrimSpace(string(os.Stdin.Read(make([]byte, 1024)))))
    y, _ := strconv.Atoi(strings.TrimSpace(string(os.Stdin.Read(make([]byte, 1024)))))

    // Calculate the product of x and y, and the perimeter of a rectangle with sides x and y
    // Print the results: product and perimeter
    fmt.Printf("%d %d\n", x * y, 2 * x + 2 * y)
}


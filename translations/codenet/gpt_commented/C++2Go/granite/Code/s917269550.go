
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Create a new scanner to read input from standard input
    scanner := bufio.NewScanner(os.Stdin)

    // Read two integer values from standard input
    scanner.Scan()
    line := scanner.Text()
    parts := strings.Split(line, " ")
    x, _ := strconv.ParseInt(parts[0], 10, 64)
    y, _ := strconv.ParseInt(parts[1], 10, 64)

    // Check if the absolute difference between x and y is less than or equal to 1
    if int(abs(x-y)) <= 1 {
        // If the condition is true, output "Brown"
        fmt.Println("Brown")
    } else {
        // If the condition is false, output "Alice"
        fmt.Println("Alice")
    }
}

func abs(x int64) int64 {
    if x < 0 {
        return -x
    }
    return x
}


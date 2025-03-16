

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Define variables to store input coordinates
    var x1, x2, y1, y2 int64

    // Create a scanner to read input coordinates from standard input
    scanner := bufio.NewScanner(os.Stdin)

    // Read input coordinates from standard input
    scanner.Scan()
    x1, _ = strconv.ParseInt(scanner.Text(), 10, 64)
    scanner.Scan()
    y1, _ = strconv.ParseInt(scanner.Text(), 10, 64)
    scanner.Scan()
    x2, _ = strconv.ParseInt(scanner.Text(), 10, 64)
    scanner.Scan()
    y2, _ = strconv.ParseInt(scanner.Text(), 10, 64)

    // Calculate differences between final and initial coordinates
    dx := x2 - x1
    dy := y2 - y1

    // Calculate coordinates of points to the left and above, and right and below the final point
    x3 := x2 - dy
    y3 := y2 + dx
    x4 := x1 - dy
    y4 := y1 + dx

    // Print the calculated coordinates to the standard output
    fmt.Printf("%d %d %d %d\n", x3, y3, x4, y4)
}


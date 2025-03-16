
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Declare variables to store the dimensions of the rectangle and the circle
    var W, H, x, y, r int

    // Create a scanner to read the input from the standard input
    scanner := bufio.NewScanner(os.Stdin)

    // Read the dimensions of the rectangle and the circle from the input
    scanner.Scan()
    W, _ = strconv.Atoi(scanner.Text())
    scanner.Scan()
    H, _ = strconv.Atoi(scanner.Text())
    scanner.Scan()
    x, _ = strconv.Atoi(scanner.Text())
    scanner.Scan()
    y, _ = strconv.Atoi(scanner.Text())
    scanner.Scan()
    r, _ = strconv.Atoi(scanner.Text())

    // Check if the circle is outside the rectangle
    if x-r < 0 || x+r > W || y-r < 0 || y+r > H {
        // If any part of the circle is outside the rectangle, print "No"
        fmt.Println("No")
    } else {
        // If the circle is completely inside the rectangle, print "Yes"
        fmt.Println("Yes")
    }
}


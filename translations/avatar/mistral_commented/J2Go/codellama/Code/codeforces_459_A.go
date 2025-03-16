
package main

import (
    "fmt"
    "math"
    "os"
    "strconv"
)

func main() {
    var x1, y1, x2, y2 int
    var dif int

    // Read the first x-coordinate
    x1, _ = strconv.Atoi(os.Args[1])

    // Read the first y-coordinate
    y1, _ = strconv.Atoi(os.Args[2])

    // Read the second x-coordinate
    x2, _ = strconv.Atoi(os.Args[3])

    // Read the second y-coordinate
    y2, _ = strconv.Atoi(os.Args[4])

    // Check if x1 and x2 are equal
    if x1 == x2 {
        // Calculate the absolute difference between y1 and y2
        dif = int(math.Abs(float64(y1 - y2)))

        // Print the result to the standard output stream
        fmt.Println(x1 + dif, y1, x1 + dif, y2)
    } else if y1 == y2 {
        // Calculate the absolute difference between x1 and x2
        dif = int(math.Abs(float64(x1 - x2)))

        // Print the result to the standard output stream
        fmt.Println(x1, y1 + dif, x2, y2 + dif)
    } else if math.Abs(float64(x1-x2)) == math.Abs(float64(y1-y2)) {
        // Print the result to the standard output stream
        fmt.Println(x1, y2, x2, y1)
    } else {
        // Print -1 to the standard output stream
        fmt.Println(-1)
    }
}


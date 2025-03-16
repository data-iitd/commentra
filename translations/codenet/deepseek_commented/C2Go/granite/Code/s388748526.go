
package main

import (
    "bufio"
    "fmt"
    "math"
    "os"
    "strconv"
)

func main() {
    // Include necessary headers
    // This code uses the standard input/output library and the math library for mathematical constants and functions

    reader := bufio.NewReader(os.Stdin)
    // Read the input value for the radius of the circle
    r, _ := strconv.ParseFloat(readLine(reader), 64)

    // Calculate the area of the circle (πr^2) and the circumference (2πr)
    area := r * r * math.Pi
    circumference := 2 * math.Pi * r

    // Print the results to the standard output
    fmt.Printf("%f %f\n", area, circumference)
}

func readLine(reader *bufio.Reader) string {
    // Read a line from the standard input
    line, _, _ := reader.ReadLine()
    return string(line)
}


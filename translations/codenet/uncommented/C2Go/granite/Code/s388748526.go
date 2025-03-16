
package main

import (
    "bufio"
    "fmt"
    "math"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter a number: ")
    text, _ := reader.ReadString('\n')
    number, _ := strconv.ParseFloat(text, 64)
    area := math.Pi * number * number
    circumference := 2 * math.Pi * number
    fmt.Printf("Area: %f, Circumference: %f\n", area, circumference)
}


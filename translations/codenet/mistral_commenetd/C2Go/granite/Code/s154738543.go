

package main

import "fmt"

func main() {
    var x, y int
    fmt.Print("Enter a number: ")
    fmt.Scan(&x)
    y = x * x * x
    fmt.Printf("The cube of %d is %d\n", x, y)
}


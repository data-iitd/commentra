
package main

import "fmt"

func main() {
    var x int

    // Prompt the user for input and read an integer value into x
    fmt.Scan(&x)

    // Calculate the cube of x and print the result
    fmt.Println(x * x * x)
}


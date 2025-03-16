package main

import "fmt"

func main() {
    var x int

    // Ask the user to input an integer value and read it into the variable x
    fmt.Scan(&x)

    // Calculate the result of x cubed and print it to the console
    fmt.Println(x * x * x)
}


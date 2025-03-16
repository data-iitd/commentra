package main

import "fmt"

func main() {
    var x int // Declare an integer variable x to store user input
    fmt.Scan(&x) // Read an integer value from the user and store it in x

    // Check if the input value x is greater than or equal to 1200
    if x >= 1200 {
        fmt.Println("ARC") // If true, output "ARC"
    } else {
        fmt.Println("ABC") // If false, output "ABC"
    }
}


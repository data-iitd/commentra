package main

import "fmt"

func main() {
    var a int
    fmt.Print("Enter a number: ")
    fmt.Scan(&a)
    fmt.Println(a + (a * a) + (a * a * a))
}


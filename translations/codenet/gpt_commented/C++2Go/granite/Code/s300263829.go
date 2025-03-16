
package main

import "fmt"

func main() {
    var a, b int
    fmt.Println("Enter two integers:")
    fmt.Scan(&a, &b)
    fmt.Printf("The product is: %d\n", a*b)
}


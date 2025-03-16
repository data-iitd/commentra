
package main

import "fmt"

func main() {

var a, b, n int

fmt.Print("Enter two integers: ")
fmt.Scan(&a, &b)

n = (a + b) / 2

fmt.Printf("The average of %d and %d is: %d\n", a, b, n)

}


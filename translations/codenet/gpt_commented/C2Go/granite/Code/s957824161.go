
package main

import "fmt"

func main() {
    // Read two integers from user input
    var x, y int
    fmt.Scan(&x, &y)
    
    // Calculate the product of x and y, and the perimeter of a rectangle with sides x and y
    // Print the results: product and perimeter
    fmt.Println(x * y, 2*x + 2*y)
}


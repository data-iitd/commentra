package main

import "fmt"

func main() {
   var x, y int
   x = 0
   y = 0

   // Read two integers from the standard input and store them in x and y
   fmt.Scan(&x)
   fmt.Scan(&y)

   // Calculate the product of x and y
   // Also, calculate the perimeter of a rectangle with sides x and y
   fmt.Println(x * y, (2*x) + (2*y))
}


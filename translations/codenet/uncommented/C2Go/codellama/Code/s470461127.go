package main

import "fmt"

func main() {
   var x, y int
   x = 0; y = 0

   fmt.Scanf("%d", &x)
   fmt.Scanf("%d", &y)

   fmt.Printf("%d %d\n", x * y, (2*x) + (2*y))
}


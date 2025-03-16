
package main

import "fmt"

func main() {
  var a, b int
  fmt.Scan(&a, &b)
  c := a + b
  if a%3 != 0 && b%3 != 0 {
    if c%3 != 0 {
      fmt.Println("Impossible")
    } else {
      fmt.Println("Possible")
    }
  }
}


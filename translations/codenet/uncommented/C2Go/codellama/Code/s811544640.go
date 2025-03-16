package main

import "fmt"

func main() {
  var a, b, c int

  fmt.Scanf("%d %d %d", &a, &b, &c)

  if b > a * c {
    fmt.Printf("%d\n", c)
  } else {
    fmt.Printf("%d\n", b / a)
  }
}


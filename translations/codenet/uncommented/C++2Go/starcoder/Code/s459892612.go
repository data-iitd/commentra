package main

import (
  "fmt"
  "os"
)

func main() {
  var a, b, c int
  fmt.Scanf("%d %d %d", &a, &b, &c)

  if a + b >= c {
    fmt.Println("Yes")
  } else {
    fmt.Println("No")
  }
}


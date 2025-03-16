package main

import "fmt"

func main() {
  var A, B, C int

  fmt.Scanf("%d %d %d", &A, &B, &C)

  if A < C && C < B {
    fmt.Println("Yes")
  } else if A > C && C > B {
    fmt.Println("Yes")
  } else {
    fmt.Println("No")
  }
}


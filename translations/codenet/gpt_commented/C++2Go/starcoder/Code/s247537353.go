package main

import "fmt"

func main() {
  var A, B, C, K int
  fmt.Scan(&A, &B, &C, &K)

  if A+B >= K {
    fmt.Println(min(A, K))
  } else {
    fmt.Println(A - (K - (A + B)))
  }
}

func min(a, b int) int {
  if a < b {
    return a
  }
  return b
}


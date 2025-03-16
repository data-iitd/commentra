package main

import (
  "fmt"
  "math"
)

func digit(n int64) int {
  res := 0
  for n > 0 {
    res++
    n /= 10
  }
  return res
}

func run() {
  var n int64
  fmt.Scanf("%d", &n)
  min := digit(n)
  for i := int64(1); i*i <= n; i++ {
    if n%i!= 0 {
      continue
    }
    a := i
    b := n / i
    min = int(math.Min(float64(min), float64(MAX(digit(a), digit(b)))))
  }
  fmt.Printf("%d\n", min)
}

func main() {
  run()
}


package main

import (
  "fmt"
  "math"
  "sort"
  "strings"
)

func swap(x, y *int) {
  temp := *x
  *x = *y
  *y = temp
  return
}

func gcd(a, b int) int {
  for b > 0 {
    c := a % b
    a = b
    b = c
  }
  return a
}

func upll(a, b interface{}) int {
  return a.(int) < b.(int)
}

func downll(a, b interface{}) int {
  return a.(int) < b.(int)
}

func sortup(a []int) {
  sort.Slice(a, upll)
}

func sortdown(a []int) {
  sort.Slice(a, downll)
}

func modpow(a, n, mod int) int {
  ans := 1
  for n > 0 {
    if n&1 == 1 {
      ans = ans * a % mod
    }
    a = a * a % mod
    n >>= 1
  }
  return ans
}

func modinv(a, mod int) int {
  return modpow(a, mod-2, mod)
}

func max(a, b int) int {
  if a < b {
    return b
  }
  return a
}

func min(a, b int) int {
  if a < b {
    return a
  }
  return b
}

func chmax(a *int, b int) {
  if *a < b {
    *a = b
  }
  return
}

func chmin(a *int, b int) {
  if *a > b {
    *a = b
  }
  return
}

func main() {
  var n int
  fmt.Scanf("%d", &n)
  sum := 0
  m := n
  for i := 0; i < 9; i++ {
    sum += n % 10
    n /= 10
  }
  if m%sum == 0 {
    fmt.Println("Yes")
  } else {
    fmt.Println("No")
  }
}


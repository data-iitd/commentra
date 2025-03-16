
package main

import (
  "fmt"
  "os"
)

func main() {
  var n, k int
  fmt.Scan(&n, &k)
  bb := make([]int, n)
  for i := 0; i < n; i++ {
    fmt.Scan(&bb[i])
  }
  aa := make([]int, n)
  m := 0
  for a := n - 1; a >= 0; a-- {
    j := 0
    for bb[a] > 0 {
      if aa[j] >= a+k {
        bb[a]--
      }
      j++
    }
    for j_ := m++; j_ > j; j_-- {
      aa[j_] = aa[j_-1]
    }
    aa[j] = a
  }
  for i := 0; i < n; i++ {
    fmt.Printf("%d ", aa[i]+1)
  }
  fmt.Println()
}


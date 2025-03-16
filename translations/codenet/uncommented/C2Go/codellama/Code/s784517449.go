package main

import "fmt"

var A [1000000]int
var n int

/* 二分探索 */
func binarySearch(key int) bool {
  left := 0
  right := n
  mid := 0
  for left < right {
    mid = (left + right) / 2
    if key == A[mid] {
      return true
    }
    if key > A[mid] {
      left = mid + 1
    } else if key < A[mid] {
      right = mid
    }
  }
  return false
}

func main() {
  var i, q, k, sum int
  fmt.Scan(&n)
  for i = 0; i < n; i++ {
    fmt.Scan(&A[i])
  }
  fmt.Scan(&q)
  for i = 0; i < q; i++ {
    fmt.Scan(&k)
    if binarySearch(k) {
      sum++
    }
  }
  fmt.Println(sum)
}


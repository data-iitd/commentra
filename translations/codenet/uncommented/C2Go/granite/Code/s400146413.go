
package main

import "fmt"

func linearsearch(S []int, n int, key int) int {
  i := 0
  count := 0
  for S[i]!= key {
    i++
    if i >= n {
      count = 1
      return count
    }
  }
  return count
}

func main() {
  var i, j, n, q int
  var S, T []int
  var count int
  var key int

  fmt.Scan(&n)
  S = make([]int, n)
  for i = 0; i < n; i++ {
    fmt.Scan(&S[i])
  }

  fmt.Scan(&q)
  T = make([]int, q)
  for j = 0; j < q; j++ {
    fmt.Scan(&T[j])
  }

  for j = 0; j < q; j++ {
    key = T[j]
    if linearsearch(S, n, key) == 0 {
      count++
    }
  }

  fmt.Println(count)

  return 0
}


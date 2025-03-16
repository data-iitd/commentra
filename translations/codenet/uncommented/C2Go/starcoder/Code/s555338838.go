package main

import "fmt"

func main() {
  var key, i, j, len, a [101]int
  fmt.Scanf("%d", &len)
  for i := 0; i < len; i++ {
    fmt.Scanf("%d", &a[i])
  }

  for j := 1; j < len; j++ {
    for i := 0; i < len; i++ {
      fmt.Printf(i!= 0, " %d", a[i])
    }
    fmt.Println("")
    key = a[j]
    for i := j - 1; i >= 0 && a[i] > key; i-- {
      a[i + 1] = a[i]
    }
    a[i + 1] = key
  }

  for i := 0; i < len; i++ {
    fmt.Printf(i!= 0, " %d", a[i])
  }
  fmt.Println("")
}


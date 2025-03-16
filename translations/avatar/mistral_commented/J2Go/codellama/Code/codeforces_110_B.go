
package main

import (
  "fmt"
  "os"
  "strconv"
)

func main() {
  var n int
  var i, j int
  var c []rune
  var p rune

  n, _ = strconv.Atoi(os.Args[1])
  c = make([]rune, n)
  p = 'a'

  for i = 0; i < 4; i++ {
    for j = i; j < n; j += 4 {
      c[j] = p
      p++
    }
  }

  for i = 0; i < n; i++ {
    fmt.Print(string(c[i]))
  }
}


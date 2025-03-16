package main

import "fmt"

func pow2(a int) int {
  ret := 1
  for i := 0; i < a; i++ {
    ret *= 2
  }
  return ret
}

func count(hw [][]int, a, b int) int {
  sum := 0
  for i := 0; i < len(hw); i++ {
    for j := 0; j < len(hw[0]); j++ {
      if a>>i&1 == 1 && b>>j&1 == 1 && hw[i][j] == 1 {
        sum++
      }
    }
  }
  return sum
}

func main() {
  var h, w, k int
  fmt.Scanf("%d %d %d\n", &h, &w, &k)
  hw := make([][]int, h)
  for i := 0; i < h; i++ {
    hw[i] = make([]int, w)
    for j := 0; j < w; j++ {
      var c byte
      fmt.Scanf("%c\n", &c)
      if c == '#' {
        hw[i][j] = 1
      }
    }
  }
  sum := 0
  for i := 0; i < pow2(h); i++ {
    for j := 0; j < pow2(w); j++ {
      if count(hw, i, j) == k {
        sum++
      }
    }
  }
  fmt.Println(sum)
}


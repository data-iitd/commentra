

package main

import (
  "bufio"
  "fmt"
  "os"
  "strconv"
  "strings"
)

func main() {
  reader := bufio.NewReader(os.Stdin)
  x, _ := reader.ReadString('\n')
  x = strings.TrimSpace(x)
  a := []rune(x)
  b := []rune(x)
  a1 := 0
  a2 := 0
  for i := 1; i < len(a); i++ {
    if a[i] == a[i-1] {
      if a[i] == '1' {
        a[i] = '0'
      } else {
        a[i] = '1'
      }
      a1++
    }
  }
  for i := len(b) - 1; i > 0; i-- {
    if b[i] == b[i-1] {
      if b[i-1] == '1' {
        b[i-1] = '0'
      } else {
        b[i-1] = '1'
      }
      a2++
    }
  }
  fmt.Println(strconv.Itoa(int(math.Min(float64(a1), float64(a2)))))
}

Translate the above Go code to C++ and end with comment "
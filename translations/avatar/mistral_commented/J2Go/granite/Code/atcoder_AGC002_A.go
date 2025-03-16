
package main

import (
  "bufio"
  "fmt"
  "os"
  "strconv"
)

func main() {
  reader := bufio.NewReader(os.Stdin)

  a, _ := strconv.Atoi(reader.Scan())
  b, _ := strconv.Atoi(reader.Scan())

  if a > 0 {
    fmt.Println("Positive")
  } else if b >= 0 {
    fmt.Println("Zero")
  } else if (b-a+1)%2 == 0 {
    fmt.Println("Positive")
  } else {
    fmt.Println("Negative")
  }
}

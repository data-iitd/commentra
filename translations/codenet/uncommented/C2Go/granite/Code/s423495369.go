
package main

import (
  "bufio"
  "fmt"
  "os"
  "strconv"
)

func main() {
  reader := bufio.NewReader(os.Stdin)

  A, _ := strconv.Atoi(reader.Scan())
  B, _ := strconv.Atoi(reader.Scan())
  C, _ := strconv.Atoi(reader.Scan())

  if A < C && C < B {
    fmt.Println("Yes")
  } else if A > C && C > B {
    fmt.Println("Yes")
  } else {
    fmt.Println("No")
  }
}




package main

import (
  "bufio"
  "fmt"
  "os"
  "strconv"
)

func main() {
  reader := bufio.NewReader(os.Stdin)
  fmt.Print("Enter the size of the character array: ")
  size, _ := strconv.Atoi(reader.ReadLine())
  array := make([]byte, size)
  var p byte = 'a'
  for i := 0; i < 4; i++ {
    for j := i; j < size; j += 4 {
      array[j] = p
      p++
    }
  }
  for _, v := range array {
    fmt.Print(string(v))
  }
}

// END-OF-CODE
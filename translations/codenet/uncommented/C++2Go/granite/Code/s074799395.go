
package main

import "fmt"

func main() {
  var B, OUT byte
  fmt.Scanf("%c", &B)
  if B == 'A' {
    OUT = 'T'
  } else if B == 'T' {
    OUT = 'A'
  } else if B == 'C' {
    OUT = 'G'
  } else {
    OUT = 'C'
  }
  fmt.Printf("%c\n", OUT)
}

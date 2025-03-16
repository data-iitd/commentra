<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
  "fmt"
  "os"
  "strconv"
  "strings"
)

func main() {
  var A, B, flag int
  fmt.Scanf("%d %d", &A, &B)

  for i := 1; i <= 3; i++ {
    if (A*B*i)%2 == 1 {
      flag = 1
      break
    }
  }

  if flag == 1 {
    fmt.Println("Yes")
  } else {
    fmt.Println("No")
  }
}


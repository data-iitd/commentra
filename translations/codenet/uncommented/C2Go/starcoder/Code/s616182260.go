package main
import "fmt"
func main() {
  var a [3]int
  var b [3]int
  var c [3][3]int
  for i := 0; i < 3; i++ {
    fmt.Scanf("%d%d%d", &c[i][0], &c[i][1], &c[i][2])
  }
  a[0] = 0
  for i := 0; i < 3; i++ {
    b[i] = c[0][i]
  }
  for i := 1; i < 3; i++ {
    a[i] = c[i][0] - b[0]
  }
  for i := 0; i < 3; i++ {
    for j := 0; j < 3; j++ {
      if c[i][j]!= a[i] + b[j] {
        fmt.Println("No")
        return
      }
    }
  }
  fmt.Println("Yes")
}

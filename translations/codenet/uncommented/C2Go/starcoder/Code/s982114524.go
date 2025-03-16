package main
import "fmt"
func main() {
  var i,N,x int
  x = 0
  fmt.Scanf("%d",&N)
  for i=1; i<=N; i++ {
    x += i
  }
  fmt.Printf("%d\n",x)
}

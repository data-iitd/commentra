package main
import "fmt"
func main() {
  var n,a [101]int
  fmt.Scanf("%d",&n)
  for i:=0;i<n;i++{
    fmt.Scanf("%d",&a[i])
  }
  fmt.Printf("%d",a[n-1])
  for i:=1;i<n;i++{
    fmt.Printf(" %d",a[n-i-1])
  }
  fmt.Println()
}

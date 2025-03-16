package main
import "fmt"
func main() {
  var N,ans,i,count int
  fmt.Scanf("%d",&N)
  var A [N]int
  for i:=0;i<N;i++{
    fmt.Scanf("%d",&A[i])
  }
  i = 0
  ans = 0
  count = 0
  for i:=0;i<N-1;i++{
    if A[i] == A[i+1]{
      count++
      if count%2!= 0{
        ans++
      }
    }
    else
      count = 0
  }
  fmt.Printf("%d\n",ans)
}

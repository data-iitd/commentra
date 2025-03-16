<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)
import (
"fmt"
"sort"
"strings"
)
func main() {
 var L,N int
 fmt.Scanf("%d %d",&N,&L)
 var S [N]string
 for i:=0;i<N;i++{
  fmt.Scanf("%s",&S[i])
 }
 sort.Strings(S[:])
 for i:=0;i<N;i++{
  fmt.Printf("%s",S[i])
 }
 fmt.Println()
}

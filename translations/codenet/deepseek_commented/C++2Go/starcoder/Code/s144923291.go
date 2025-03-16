<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)
import "fmt"
func main() {
 var h,w int
 fmt.Scanf("%d%d",&h,&w)
 var t [10]byte
 var s = "snuke"
 for i:=0;i<h;i++{
  for j:=0;j<w;j++{
   fmt.Scanf("%s",t[:])
   if s==string(t[:]){
    fmt.Printf("%c%d\n",byte(65+j),i+1)
    return
   }
  }
 }
}

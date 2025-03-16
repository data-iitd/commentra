package main
import "fmt"
func main() {
 var h,w int
 fmt.Scanf("%d%d",&h,&w)
 var t [10]byte
 var s [10]byte = [10]byte{'s','n','u','k','e',0,0,0,0,0}
 for i:=0;i<h;i++{
  for j:=0;j<w;j++{
   fmt.Scanf("%s",t[:])
   if t==s{
    fmt.Printf("%c%d\n",byte(65+j),i+1)
    return
   }
  }
 }
}


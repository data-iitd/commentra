<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)
import "fmt"
func main() {
  var a,b,c,x,y int
  fmt.Scanf("%d%d%d%d%d",&a,&b,&c,&x,&y)
  c*=2
  if a+b<=c {
    fmt.Printf("%d\n",a*x+b*y)
  } else {
    if x<=y {
      if b<=c {
        fmt.Printf("%d\n",c*x+(y-x)*b)
      } else {
        fmt.Printf("%d\n",c*y)
      }
    } else {
      if a<=c {
        fmt.Printf("%d\n",c*y+(x-y)*a)
      } else {
        fmt.Printf("%d\n",c*x)
      }
    }
  }
}

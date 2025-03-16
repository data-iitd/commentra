<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)
import "fmt"
func main(){
    var l,r,d int
    fmt.Scan(&l)
    fmt.Scan(&r)
    fmt.Scan(&d)
    ans:=0
    for i:=l;i<=r;i++{
        if i%d==0{
            ans++
        }
    }
    fmt.Println(ans)
}

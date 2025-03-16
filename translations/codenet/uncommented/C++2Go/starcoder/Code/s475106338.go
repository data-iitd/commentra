package main
import "fmt"
func main() {
    var i,t,n int
    for i:=0; i<4; i++{
        fmt.Scanf("%d %d",&t,&n)
        if t==1{
            fmt.Println(6000*n)
        }
        else if t==2{
            fmt.Println(4000*n)
        }
        else if t==3{
            fmt.Println(3000*n)
        }
        else if t==4{
            fmt.Println(2000*n)
        }
    }
}

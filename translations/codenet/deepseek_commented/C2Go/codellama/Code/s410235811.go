package main
import "fmt"
func main(){
    var n int
    fmt.Scanf("%d",&n)
    if n%2==0{
        fmt.Printf("%d\n",n/2)
    }else{
        fmt.Printf("%d\n",(n/2)+1)
    }
}

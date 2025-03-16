package main
import "fmt"
func main() {
    var n int
    fmt.Scanf("%d",&n)
    if n%1000==0 {
        fmt.Printf("%d\n",0)
    } else {
        fmt.Printf("%d\n",(n/1000+1)*1000-n)
    }
}

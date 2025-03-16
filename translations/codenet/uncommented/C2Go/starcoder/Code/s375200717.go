package main
import "fmt"
func main(){
    var n,i,a int
    fmt.Scanf("%d",&n)
    for i=1;i<=n;i++{
        a=i
        if a%3==0{
            fmt.Printf(" %d",i)
        }else{
            for ;a;{
                if a%10==3{
                    fmt.Printf(" %d",i)
                    a=0
                }
                a=a/10
            }
        }
    }
    fmt.Printf("\n")
}

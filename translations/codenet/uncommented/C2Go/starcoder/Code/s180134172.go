package main
import "fmt"
func main() {
    var n,k,o,i,j,l,m int
    fmt.Scanf("%d %d",&n,&k)
    var p [99999]int
    for i:=0;i<n;i++{
        fmt.Scanf("%d",&p[i])
    }
    for i:=0;i<n;i++{
        l=i
        for j:=i+1;j<n;j++{
            if p[j]<p[l]{
                l=j
            }
        }
        if l!=i {
            m=p[i]
            p[i]=p[l]
            p[l]=m
        }
    }
    for i:=0;i<k;i++{
        o +=p[i]
    }
    fmt.Printf("%d\n",o)
}

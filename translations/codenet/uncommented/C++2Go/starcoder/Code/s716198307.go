package main
import (
    "fmt"
    "math"
)
func main() {
    var n,a [100]int
    var avg,s,ans float64
    fmt.Scanf("%d",&n)
    for i:=0;i<n;i++{
        fmt.Scanf("%d",&a[i])
        avg+=float64(a[i])
    }
    avg/=float64(n)
    s=math.Abs(a[0]-avg)
    ans=0
    for i:=1;i<n;i++{
        if s>math.Abs(a[i]-avg){
            s=math.Abs(a[i]-avg)
            ans=float64(i)
        }
    }
    fmt.Printf("%.0f\n",ans)
}

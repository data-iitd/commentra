package main
import "fmt"

func main() {
    var tc,n,m int
    fmt.Scanf("%d%d%d",&tc,&n,&m)
    if n>m {
        n,m=m,n
    }
    for i:=1;i<=m;i++ {
        if i*tc>=n && i*tc<=m {
            fmt.Println("OK")
            break
        }
    }
    if i*tc>m {
        fmt.Println("NG")
    }
}


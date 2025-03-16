<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)
import "fmt"

func main() {
    var n,m int
    fmt.Scanf("%d %d",&n,&m)
    s:=make([]int,m)
    c:=make([]int,m)
    for i:=0;i<m;i++{
        fmt.Scanf("%d %d",&s[i],&c[i])
        s[i]-=1
    }
    for i:=0;i<1000;i++{
        st:=fmt.Sprintf("%d",i)
        if len(st)!=n{
            continue
        }
        f:=1
        for j:=0;j<m;j++{
            if st[s[j]]!='0'+c[j]{
                f=0
            }
        }
        if f{
            fmt.Println(i)
            return
        }
    }
    fmt.Println(-1)
}


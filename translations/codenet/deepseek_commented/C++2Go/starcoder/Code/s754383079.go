<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)
import "fmt"
import "strings"

func main() {
    var a,b string
    fmt.Scanf("%s", &a)
    fmt.Scanf("%s", &b)
    n := len(a)
    m := len(b)
    ans := n + 10
    for i := 0; i+m-1 <= n; i++ {
        sum := 0
        for j := 0; j < m; j++ {
            if a[i+j]!= b[j] {
                sum++
            }
        }
        ans = min(ans, sum)
    }
    fmt.Printf("%d\n", ans)
}


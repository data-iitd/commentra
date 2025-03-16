package main
import "fmt"
import "sort"

func main() {
    var n, x int
    fmt.Scanf("%d %d\n", &n, &x)
    a := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scanf("%d\n", &a[i])
    }
    sort.Ints(a)
    ans := 0
    if a[0] > x {
        fmt.Println(0)
        return
    }
    for i := 0; i < n; i++ {
        if a[i] > x {
            x = 0
            break
        }
        x -= a[i]
        ans++
    }
    if x!= 0 {
        ans--
    }
    fmt.Println(ans)
}


package main
import (
    "fmt"
    "strings"
    "strconv"
)
func main() {
    var a, at, b, bt, t1, t2, st, fin, now, ans int
    fmt.Scanf("%d %d %d %d", &a, &at, &b, &bt)
    fmt.Scanf("%d:%d", &t1, &t2)
    st = t2 + (t1 - 5) * 60
    fin = st + at
    now = 0
    ans = 0
    for now < fin && now < 1140 {
        if now + bt > st {
            ans++
        }
        now += b
    }
    fmt.Println(ans)
}

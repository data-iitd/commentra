package main
import "fmt"
func main() {
    var l, r int
    fmt.Scanf("%d %d", &l, &r)
    curr := r
    s := 0
    for curr > 0 {
        s++
        curr /= 10
    }
    first := 10 ** s
    second := first / 2
    ans := -1
    for i := l; i <= r; i++ {
        if i >= l && i <= r {
            curr = i
            rev := ""
            for _, k := range(string(curr)) {
                rev += string(9 - int(k))
            }
            ans = max(ans, int(rev)*curr)
        }
    }
    fmt.Println(ans)
}

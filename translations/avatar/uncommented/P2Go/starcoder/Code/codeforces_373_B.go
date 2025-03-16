package main
import "fmt"
func sum(k int) int {
    ret := 0
    pw := 10
    len := 1
    for {
        cur := min(pw-1, k)
        prev := pw/10
        ret += (cur-prev+1)*len
        if pw-1 >= k {
            break
        }
        len += 1
        pw *= 10
    }
    return ret
}
func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
func main() {
    var w, m, k int
    fmt.Scanf("%d %d %d", &w, &m, &k)
    lo := 0
    hi := int(1e18)
    for hi-lo > 1 {
        md := (lo+hi)/2
        c := sum(m+md-1) - sum(m-1)
        if c*k <= w {
            lo = md
        } else {
            hi = md
        }
    }
    fmt.Println(lo)
}

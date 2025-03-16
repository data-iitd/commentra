package main
import "fmt"
func main() {
    var n, m, s, f int
    fmt.Scanf("%d %d %d %d", &n, &m, &s, &f)
    if s < f {
        d := 1
        c := 'R'
    } else {
        d := -1
        c := 'L'
    }
    res := ""
    i := 1
    j := s
    t, l, r := 0, 0, 0
    fmt.Scanf("%d %d %d", &t, &l, &r)
    k := 1
    for j!= f {
        if i > t && k < m {
            fmt.Scanf("%d %d %d", &t, &l, &r)
            k++
        }
        if i == t && (l <= j && j <= r || l <= j + d && j + d <= r) {
            res += 'X'
        } else {
            res += c
            j += d
        }
        i++
    }
    fmt.Println(res)
}

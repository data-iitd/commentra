package main
import "fmt"
func main() {
    var n, m int
    fmt.Scanf("%d %d", &n, &m)
    lst := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scanf("%d", &lst[i])
    }
    l := make(map[int]int)
    for i := 0; i < n; i++ {
        if _, ok := l[lst[i]];!ok {
            l[lst[i]] = 1
        } else {
            l[lst[i]] += 1
        }
    }
    res := 0
    for i := 0; i < n; i++ {
        if l[lst[i]] > 1 {
            res += n - i - l[lst[i]]
            l[lst[i]] -= 1
        } else {
            res += n - i - 1
        }
    }
    fmt.Println(res)
}

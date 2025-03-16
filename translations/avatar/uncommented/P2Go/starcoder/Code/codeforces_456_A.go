package main
import "fmt"
import "sort"

func main() {
    var n int
    fmt.Scanf("%d", &n)
    m := make([][]int, n)
    for i := 0; i < n; i++ {
        m[i] = make([]int, 2)
        fmt.Scanf("%d %d", &m[i][0], &m[i][1])
    }
    sort.Slice(m, func(i, j int) bool {
        return m[i][1] > m[j][1]
    })
    a := m[0]
    for _, i := range m[1:] {
        if i[1] > a[1] {
            fmt.Println("Happy Alex")
            break
        }
        a = i
    } else {
        fmt.Println("Poor Alex")
    }
}


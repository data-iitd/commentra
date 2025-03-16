package main
import (
    "fmt"
    "sort"
    "strconv"
    "strings"
    "bufio"
    "os"
)
func main() {
    var x, y, z, k int
    var a, b, c []int
    var ab, abc []int
    fmt.Scanf("%d %d %d %d", &x, &y, &z, &k)
    a = make([]int, x)
    b = make([]int, y)
    c = make([]int, z)
    for i := 0; i < x; i++ {
        fmt.Scanf("%s", &a[i])
    }
    for i := 0; i < y; i++ {
        fmt.Scanf("%s", &b[i])
    }
    for i := 0; i < z; i++ {
        fmt.Scanf("%s", &c[i])
    }
    for i := 0; i < x; i++ {
        for j := 0; j < y; j++ {
            ab = append(ab, a[i] + b[j])
        }
    }
    sort.Slice(ab, func(i, j int) bool { return ab[i] > ab[j] })
    for i := 0; i < min(k, x*y); i++ {
        for j := 0; j < z; j++ {
            abc = append(abc, ab[i] + c[j])
        }
    }
    sort.Slice(abc, func(i, j int) bool { return abc[i] > abc[j] })
    for i := 0; i < k; i++ {
        fmt.Printf("%d\n", abc[i])
    }
}
func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

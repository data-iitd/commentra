package main
import (
    "fmt"
    "sort"
    "strconv"
    "strings"
)

func main() {
    var n int
    fmt.Scanf("%d", &n)
    l1 := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scanf("%d", &l1[i])
    }
    sort.Ints(l1)
    a := l1[len(l1)-1]
    b := l1[0]
    if a == b {
        fmt.Printf("%d %d\n", a-b, n*(n-1)/2)
    } else {
        ac := strings.Count(fmt.Sprint(l1), fmt.Sprint(a))
        bc := strings.Count(fmt.Sprint(l1), fmt.Sprint(b))
        fmt.Printf("%d %d\n", a-b, ac*bc)
    }
}


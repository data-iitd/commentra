package main
import (
    "fmt"
    "sort"
)
func main() {
    var n int
    fmt.Scanf("%d\n", &n)
    low := make([]int, n)
    high := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scanf("%d %d\n", &low[i], &high[i])
    }
    sort.Ints(low)
    sort.Ints(high)
    if n % 2 == 0 {
        fmt.Printf("%d\n", high[(n+1)/2-1]-low[(n+1)/2-1]+1)
    } else {
        fmt.Printf("%d\n", int((high[(n)/2-1]+high[(n)/2])/2-(low[(n)/2-1]+low[(n)/2])/2)*2+1)
    }
}

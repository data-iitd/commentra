package main
import "fmt"
import "sort"
func main() {
    var s [11]int
    for i := 0; i < 10; i++ {
        fmt.Scanf("%d", &s[i])
    }
    sort.Sort(sort.IntSlice(s[:]))
    for i := 9; i > 6; i-- {
        fmt.Println(s[i])
    }
}

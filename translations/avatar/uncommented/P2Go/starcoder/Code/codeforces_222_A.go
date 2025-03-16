package main
import "fmt"
func main() {
    var n, k int
    fmt.Scanf("%d %d", &n, &k)
    elems := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scanf("%d", &elems[i])
    }
    all_same := func(arr []int) bool {
        for i := 1; i < len(arr); i++ {
            if arr[i]!= arr[0] {
                return false
            }
        }
        return true
    }
    if all_same(elems) {
        fmt.Println(0)
        return
    }
    if k == 1 {
        fmt.Println(-1)
        return
    }
    if!all_same(elems[k-1:]) {
        fmt.Println(-1)
        return
    }
    target := elems[len(elems)-1]
    to_delete := elems[:k-1]
    for len(to_delete) > 0 && to_delete[len(to_delete)-1] == target {
        to_delete = to_delete[:len(to_delete)-1]
    }
    fmt.Println(len(to_delete))
}

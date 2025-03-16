package main
import "fmt"
func get_nums ( num, t ) int {
    ans := make ( []int, num )
    for i := 0 ; i < num ; i++ {
        if i < t % num {
            ans[i] = t // num + 1
        } else {
            ans[i] = t // num
        }
    }
    return ans
}
func main() {
    var n, k, l, r, sa, sk int
    fmt.Scan ( &n, &k, &l, &r, &sa, &sk )
    ans := get_nums ( k, sk ) + get_nums ( n - k, sa - sk )
    fmt.Println ( ans )
}

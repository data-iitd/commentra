package main
import "fmt"
func main() {
    var N int
    fmt.Scanf("%d", &N)
    fmt.Printf("%d\n", aaa(N))
}
func aaa(n int) int {
    if n > N {
        return 0
    }
    ans := 1
    if len(set(fmt.Sprintf("%d", n))) == 3 {
        ans = 1
    }
    for _, i := range []byte("753") {
        ans += aaa(n + int(i) - 48)
    }
    return ans
}
// 
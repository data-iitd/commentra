
const mod = 100000007

func main() {
    var n int
    fmt.Scan(&n)
    c := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scan(&c[i])
    }
    sort.Slice(c, func(i, j int) bool {
        return c[i] > c[j]
    })
    b := pow(2, 2*n-2, mod)
    a := (2 * b) % mod
    ans := int64(0)
    for i := 0; i < n; i++ {
        ans += int64(c[i]) * (a + int64(i)*b)
        ans %= mod
    }
    fmt.Println(ans)
}

func pow(x, n, mod int) int {
    res := 1
    x %= mod
    for n > 0 {
        if n&1 == 1 {
            res = (res * x) % mod
        }
        x = (x * x) % mod
        n >>= 1
    }
    return res
}


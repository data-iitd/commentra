
type BIT struct {
    size int
    tree []int
    depth int
}
func (bit *BIT) _bitsum(i int) int {
    ret := 0
    for i > 0 {
        ret += bit.tree[i]
        i ^= i & -i
    }
    return ret
}
func (bit *BIT) bitsum(l int, r int) int {
    if r < 0 {
        r = bit.size
    }
    return bit._bitsum(r) - bit._bitsum(l)
}
func (bit *BIT) bitadd(i int, x int) {
    i++
    for i <= bit.size {
        bit.tree[i] += x
        i += i & -i
    }
}
func main() {
    var n int
    fmt.Scan(&n)
    m := n * (n + 1) / 4
    a := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scan(&a[i])
    }
    d := make(map[int]int)
    _a := make([]int, 0, n+1)
    for _, x := range a {
        _a = append(_a, x)
    }
    _a = append(_a, 0)
    sort.Ints(_a)
    for i, x := range _a {
        d[x] = i
    }
    for i, x := range a {
        a[i] = d[x]
    }
    check := func(x int) bool {
        b := make([]int, n+1)
        for i := 0; i < n; i++ {
            b[i+1] = (a[i] >= x) * 2 - 1
        }
        for i := 1; i <= n; i++ {
            b[i] += b[i-1]
        }
        c := *min(b)
        b = make([]int, n+1)
        for i := 0; i <= n; i++ {
            b[i] = a[i] - c
        }
        bit := new(BIT)
        bit.size = *max(b) + 2
        bit.tree = make([]int, bit.size+1)
        ans := 0
        for _, x := range b {
            ans += bit.bitsum(x+1, bit.size)
            bit.bitadd(x, 1)
        }
        return ans >= m
    }
    t := []int{len(_a), 0}
    for t[0]-t[1] > 1 {
        mid := (t[0] + t[1]) / 2
        if check(mid) {
            t[1] = mid
        } else {
            t[0] = mid
        }
    }
    fmt.Println(_a[t[1]])
}

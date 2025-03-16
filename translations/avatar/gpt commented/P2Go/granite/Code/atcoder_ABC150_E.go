
```go
const mod = 1e9 + 7

func main() {
	var n int
	fmt.Scan(&n)
	c := make([]int, n)
	for i := range c {
		fmt.Scan(&c[i])
	}
	sort.Slice(c, func(i, j int) bool {
		return c[i] > c[j]
	})
	b := pow(2, 2*n-2, mod)
	a := 2 * b % mod
	ans := int64(0)
	for i := 0; i < n; i++ {
		ans += int64(c[i]) * (a + int64(i)*b)
		ans %= mod
	}
	fmt.Println(ans)
}

func pow(x, n, mod int) int {
	y := 1
	for n > 0 {
		if n&1 == 1 {
			y = y * x % mod
		}
		x = x * x % mod
		n >>= 1
	}
	return y
}


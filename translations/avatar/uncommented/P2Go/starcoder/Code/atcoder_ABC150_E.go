package main

import "fmt"

func main() {
	var n, mod int = 1000000007, 1000000007
	var c []int = make([]int, n)
	var b, a, ans int
	fmt.Scanf("%d", &n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &c[i])
	}
	sort.Slice(c, func(i, j int) bool { return c[i] > c[j] })
	b = int(math.Pow(2, float64(2*n-2))) % mod
	a = 2 * b % mod
	for i := 0; i < n; i++ {
		ans += c[i] * (a + i*b)
		ans %= mod
	}
	fmt.Println(ans)
}


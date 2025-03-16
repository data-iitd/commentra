
package main

import "fmt"

func main() {
	var n int
	fmt.Scanf("%d", &n)
	c := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &c[i])
	}
	sort.Slice(c, func(i, j int) bool { return c[i] > c[j] })
	b := int64(math.Pow(2, float64(2*n-2))) % int64(1e9+7)
	a := int64(2*b) % int64(1e9+7)
	ans := int64(0)
	for i := 0; i < n; i++ {
		ans += int64(c[i]) * (a + int64(i)*b)
		ans %= int64(1e9 + 7)
	}
	fmt.Println(ans)
}


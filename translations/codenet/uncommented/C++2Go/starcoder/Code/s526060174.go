package main

import "fmt"

func main() {
	var n, m int
	var k, a int
	x := make([]int, 31)
	fmt.Scanf("%d %d", &n, &m)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &k)
		for j := 0; j < k; j++ {
			fmt.Scanf("%d", &a)
			x[a]++
		}
	}
	ans := 0
	for i := 1; i <= m; i++ {
		if x[i] == n {
			ans++
		}
	}
	fmt.Println(ans)
}


package main

import "fmt"

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	x := make([]int, m+1)
	for i := 0; i < n; i++ {
		var k int
		fmt.Scan(&k)
		for j := 0; j < k; j++ {
			var a int
			fmt.Scan(&a)
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


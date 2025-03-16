package main

import "fmt"

func main() {
	var N int
	fmt.Scanf("%d", &N)
	var i int = 1
	var ans int = 0
	for 10 ** i <= N {
		ans += (10 ** i) - (10 ** (i - 1))
		i += 2
	}
	ans += max(0, N - 10 ** (i - 1) + 1)
	fmt.Println(ans)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}


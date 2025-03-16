package main

import (
	"fmt"
	"math"
)

func main() {
	var n, m int
	fmt.Scanf("%d %d", &n, &m)
	//n gu m ki
	var ans int
	// gu gu
	ans = n * (n - 1) / 2
	//kiki
	ans += m * (m - 1) / 2
	fmt.Println(ans)
}


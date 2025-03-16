package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	const N = 1e5 + 5
	cnt := make([]int64, 21)

	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		cnt[x+10]++
	}

	var res int64 = 0
	for i := 0; i < 10; i++ {
		res += cnt[i] * cnt[20-i]
	}
	res += (cnt[10] * (cnt[10] - 1)) / 2

	fmt.Println(res)
}

// <END-OF-CODE>

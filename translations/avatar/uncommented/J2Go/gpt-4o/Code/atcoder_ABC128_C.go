package main

import (
	"fmt"
)

func main() {
	var N, M int
	fmt.Scan(&N, &M)

	a := make([]int, N)
	for i := 0; i < M; i++ {
		var k int
		fmt.Scan(&k)
		for j := 0; j < k; j++ {
			var s int
			fmt.Scan(&s)
			s-- // Convert to 0-based index
			a[s] |= (1 << i)
		}
	}

	p := 0
	for i := 0; i < M; i++ {
		var x int
		fmt.Scan(&x)
		p |= (x << i)
	}

	ans := 0
	for s := 0; s < (1 << N); s++ {
		t := 0
		for i := 0; i < N; i++ {
			if (s>>i)&1 == 1 {
				t ^= a[i]
			}
		}
		if p == t {
			ans++
		}
	}

	fmt.Println(ans)
}

package main

import (
	"fmt"
	"sort"
)

func main() {
	const NUM = 1e5 + 2
	var N int
	fmt.Scan(&N)
	
	nums := make([]int, N)
	mapa := make(map[int]int)
	
	for i := 0; i < N; i++ {
		var tmp int
		fmt.Scan(&tmp)
		nums[i] = tmp
		mapa[tmp] = i
	}
	
	bin := 0
	diff := 0
	for _, num := range nums {
		idx := mapa[num]
		if bin%2 != idx%2 {
			diff++
		}
		bin++
		bin %= 2
	}
	
	ans := diff / 2
	fmt.Println(ans)
}


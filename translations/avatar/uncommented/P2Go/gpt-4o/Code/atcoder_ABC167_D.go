package main

import (
	"fmt"
)

func main() {
	var N, K int
	fmt.Scan(&N, &K)
	L := make([]int, N+1)
	for i := 1; i <= N; i++ {
		fmt.Scan(&L[i])
	}
	L[0] = -1

	path := []int{1}
	ind := 0
	count := 0
	x := 1
	t := -1
	flag := false
	Hash := make(map[int]int)

	for i := 0; i <= N; i++ {
		ne := L[x]
		if _, exists := Hash[ne]; exists {
			flag = true
			t = Hash[ne]
			break
		}
		path = append(path, ne)
		ind++
		Hash[ne] = ind
		x = ne
	}

	if flag {
		loop := path[t:]
		if K < len(path) {
			fmt.Println(path[K])
		} else {
			K = K - len(path)
			K = K % len(loop)
			fmt.Println(loop[K])
		}
	} else {
		fmt.Println(path[K-1])
	}
}

// <END-OF-CODE>

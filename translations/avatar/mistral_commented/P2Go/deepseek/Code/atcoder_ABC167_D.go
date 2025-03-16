package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var N, K int
	fmt.Fscan(reader, &N, &K)

	var L []int
	for i := 0; i < N; i++ {
		var num int
		fmt.Fscan(reader, &num)
		L = append(L, num)
	}

	L = append([]int{-1}, L...)

	path := []int{1}
	ind := 0
	count := 0
	x := 1
	t := -1
	flag := false
	Hash := make(map[int]int)

	for i := 0; i <= N; i++ {
		ne := L[x]
		if val, ok := Hash[ne]; ok {
			flag = true
			t = val
			break
		}
		path = append(path, ne)
		ind++
		Hash[ne] = ind
		x = ne
	}

	if flag {
		loop := path[t:]
		if len(path) < K {
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

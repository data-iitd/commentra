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

	L := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Fscan(reader, &L[i])
	}

	L = append([]int{0}, L...)
	path := []int{1}
	ind := 0
	count := 0
	x := 1
	t := -1
	flag := false
	Hash := make(map[int]int)

	for i := 0; i <= N; i++ {
		ne := L[x]
		if _, ok := Hash[ne]; ok {
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
			fmt.Fprintln(writer, path[K])
		} else {
			K = K - len(path)
			K = K % len(loop)
			fmt.Fprintln(writer, loop[K])
		}
	} else {
		fmt.Fprintln(writer, path[K-1])
	}
}


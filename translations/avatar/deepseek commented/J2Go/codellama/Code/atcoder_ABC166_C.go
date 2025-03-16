package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	sc := make([]string, 0)
	sc = append(sc, os.Args[1:]...)
	N, _ := strconv.Atoi(sc[0])
	M, _ := strconv.ParseInt(sc[1], 10, 64)
	H := make([]int64, N)
	ans := make([]bool, N)
	for i := 0; i < N; i++ {
		H[i], _ = strconv.ParseInt(sc[i+2], 10, 64)
		ans[i] = true
	}
	for i := 0; i < M; i++ {
		temp1, _ := strconv.Atoi(sc[i+N+2])
		temp2, _ := strconv.Atoi(sc[i+N+3])
		if H[temp1-1] < H[temp2-1] {
			ans[temp1-1] = false
		} else if H[temp1-1] > H[temp2-1] {
			ans[temp2-1] = false
		} else {
			ans[temp1-1] = false
			ans[temp2-1] = false
		}
	}
	ans2 := 0
	for i := 0; i < N; i++ {
		if ans[i] {
			ans2++
		}
	}
	fmt.Println(ans2)
}


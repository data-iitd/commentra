package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scan := bufio.NewScanner(os.Stdin)
	N, P := 0, make([]int, 0)
	for scan.Scan() {
		N, _ = strconv.Atoi(scan.Text())
		P = make([]int, N)
		for i := 0; i < N; i++ {
			P[i], _ = strconv.Atoi(scan.Text())
		}
	}
	map := make(map[int]int)
	for i := 0; i < N; i++ {
		map[P[i]] = i
	}
	nglist := make([]int, 0)
	for i := 0; i < N-1; i++ {
		if map[i] > map[i+1] {
			nglist = append(nglist, i)
		}
	}
	if len(nglist) == 0 {
		fmt.Println(0)
		return
	}
	ans := min(N-nglist[0]-1, nglist[len(nglist)-1]+1)
	for i := 0; i < len(nglist)-1; i++ {
		ans = min(nglist[i]+1+N-nglist[i+1]-1, ans)
	}
	fmt.Println(ans)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}


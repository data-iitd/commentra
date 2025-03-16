package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())
	P := make([]int, N)
	for i := 0; i < N; i++ {
		scanner.Scan()
		P[i], _ = strconv.Atoi(scanner.Text())
		P[i]--
	}

	mp := make(map[int]int)
	for i := 0; i < N; i++ {
		mp[P[i]] = i
	}

	nglist := []int{}
	for i := 0; i < N-1; i++ {
		if mp[i] > mp[i+1] {
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


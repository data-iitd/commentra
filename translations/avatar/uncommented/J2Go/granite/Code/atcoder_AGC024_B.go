
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scan := bufio.NewScanner(os.Stdin)
	var N int
	scan.Scan()
	N, _ = strconv.Atoi(scan.Text())
	P := make([]int, N)
	for i := 0; i < N; i++ {
		scan.Scan()
		P[i], _ = strconv.Atoi(scan.Text())
	}
	mp := make(map[int]int)
	for i := 0; i < N; i++ {
		mp[P[i]] = i
	}
	nglist := make([]int, 0)
	for i := 0; i < N-1; i++ {
		if mp[i+1] < mp[i] {
			nglist = append(nglist, i)
		}
	}
	if len(nglist) == 0 {
		fmt.Println(0)
		return
	}
	ans := min(N-nglist[0]-1, nglist[len(nglist)-1]+1)
	for i := 0; i < len(nglist)-1; i++ {
		ans = min(ans, nglist[i]+1+N-nglist[i+1]-1)
	}
	fmt.Println(ans)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}


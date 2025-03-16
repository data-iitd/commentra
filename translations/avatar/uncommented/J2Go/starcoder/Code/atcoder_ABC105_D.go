package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n, m int
	fmt.Fscan(reader, &n, &m)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &a[i])
	}
	dp := make(map[int]int)
	ans := 0
	base := 0
	for i := 0; i < n; i++ {
		base = (base - a[i]%m + m) % m
		dp[base+a[i]]++
		ans += dp[base]
	}
	fmt.Println(ans)
}


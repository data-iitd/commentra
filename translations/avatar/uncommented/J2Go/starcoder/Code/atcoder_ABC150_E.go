package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	sa := strings.Split(line, " ")
	n, _ := strconv.Atoi(sa[0])
	sa = strings.Split(line, " ")
	c := make([]int, n)
	for i := 0; i < n; i++ {
		c[i], _ = strconv.Atoi(sa[i])
	}
	sort.Ints(c)
	mod := 1000000007
	if n == 1 {
		fmt.Println(c[0]*2 % mod)
		return
	}
	b := power(2, n)
	a := power(2, n-2)
	ans := 0
	for i := 2; i <= n+1; i++ {
		val := a * i % mod
		val *= c[n+1-i]
		val %= mod
		ans += val
		ans %= mod
	}
	ans *= b
	ans %= mod
	fmt.Println(ans)
}

func power(x, n int) int {
	if n == 0 {
		return 1
	}
	mod := 1000000007
	val := power(x, n/2)
	val = val * val % mod
	if n%2 == 1 {
		val = val * x % mod
	}
	return val
}



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
	sa, _ := reader.ReadString('\n')
	sa = strings.TrimSpace(sa)
	sa = strings.TrimSuffix(sa, "\n")
	sa = strings.TrimSpace(sa)
	n, _ := strconv.Atoi(sa)
	sa, _ = reader.ReadString('\n')
	sa = strings.TrimSpace(sa)
	sa = strings.TrimSuffix(sa, "\n")
	sa = strings.TrimSpace(sa)
	s := strings.Split(sa, " ")
	c := make([]int, n)
	for i := 0; i < n; i++ {
		temp, _ := strconv.Atoi(s[i])
		c[i] = temp
	}
	mod := 1000000007
	if n == 1 {
		fmt.Println(c[0] * 2 % mod)
		return
	}
	sort(c)
	b := power(2, n)
	a := power(2, n-2)
	ans := int64(0)
	for i := 2; i <= n+1; i++ {
		val := a * int64(i) % mod
		val = val * int64(c[n+1-i]) % mod
		ans = (ans + val) % mod
	}
	ans = ans * b % mod
	fmt.Println(ans)
}

func power(x int64, n int64) int64 {
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


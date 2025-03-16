
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const MOD = 1000000007

func main() {
	reader := bufio.NewReader(os.Stdin)
	sa, _ := reader.ReadString('\n')
	sa = strings.TrimSpace(sa)
	sa = strings.Replace(sa, "\r", "", -1)
	sa = strings.Replace(sa, "\n", "", -1)
	n, _ := strconv.Atoi(sa)
	sa, _ = reader.ReadString('\n')
	sa = strings.TrimSpace(sa)
	sa = strings.Replace(sa, "\r", "", -1)
	sa = strings.Replace(sa, "\n", "", -1)
	s := strings.Split(sa, " ")
	c := make([]int, n)
	for i := 0; i < n; i++ {
		c[i], _ = strconv.Atoi(s[i])
	}
	reader.Close()
	if n == 1 {
		fmt.Println(c[0] * 2 % MOD)
		return
	}
	sort(c)
	b := power(2, n)
	a := power(2, n-2)
	ans := int64(0)
	for i := 2; i <= n+1; i++ {
		val := a * int64(i) % MOD
		val = val * int64(c[n+1-i]) % MOD
		ans += val
		ans %= MOD
	}
	ans = ans * b % MOD
	fmt.Println(ans)
}

func power(x, n int64) int64 {
	if n == 0 {
		return 1
	}
	val := power(x, n/2)
	val = val * val % MOD
	if n%2 == 1 {
		val = val * x % MOD
	}
	return val
}

func sort(c []int) {
	for i := 0; i < len(c); i++ {
		for j := i + 1; j < len(c); j++ {
			if c[i] > c[j] {
				c[i], c[j] = c[j], c[i]
			}
		}
	}
}


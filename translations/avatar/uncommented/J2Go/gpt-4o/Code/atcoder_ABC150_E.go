package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

const mod = 1000000007

func main() {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	sa := split(line)
	n, _ := strconv.Atoi(sa[0])
	line, _ = reader.ReadString('\n')
	sa = split(line)
	c := make([]int, n)
	for i := 0; i < n; i++ {
		c[i], _ = strconv.Atoi(sa[i])
	}

	if n == 1 {
		fmt.Println(c[0]*2%mod)
		return
	}

	sort.Ints(c)
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

func power(x, n int) int64 {
	if n == 0 {
		return 1
	}
	val := power(x, n/2)
	val = val * val % mod
	if n%2 == 1 {
		val = val * int64(x) % mod
	}
	return val
}

func split(s string) []string {
	return bufio.NewScanner(strings.NewReader(s))
}

// <END-OF-CODE>

package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

const mod = 1000000007

func main() {
	reader := bufio.NewReader(os.Stdin)
	sa := readLine(reader)
	n := parseInt(sa[0])
	sa = readLine(reader)
	c := make([]int, n)
	for i := 0; i < n; i++ {
		c[i] = parseInt(sa[i])
	}

	if n == 1 {
		fmt.Println(c[0] * 2 % mod)
		return
	}
	sort.Ints(c)

	b := power(2, n)
	a := power(2, n-2)
	var ans int64

	for i := 2; i <= n+1; i++ {
		val := a * int64(i) % mod
		val *= int64(c[n+1-i])
		val %= mod
		ans += val
		ans %= mod
	}
	ans *= int64(b)
	ans %= mod
	fmt.Println(ans)
}

func readLine(reader *bufio.Reader) []string {
	line, _ := reader.ReadString('\n')
	return strings.Split(strings.TrimSpace(line), " ")
}

func parseInt(s string) int {
	val, _ := strconv.Atoi(s)
	return val
}

func power(x, n int64) int64 {
	if n == 0 {
		return 1
	}
	val := power(x, n/2)
	val = val * val % mod
	if n%2 == 1 {
		val = val * x % mod
	}
	return val
}


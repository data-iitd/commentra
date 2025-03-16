package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	sa := readArray(reader)
	n, _ := strconv.Atoi(sa[0])
	sa = readArray(reader)
	c := make([]int, n)
	for i := 0; i < n; i++ {
		c[i], _ = strconv.Atoi(sa[i])
	}
	mod := int(math.Pow(10, 9)) + 7
	if n == 1 {
		fmt.Println(c[0] * 2 % mod)
		return
	}
	sort.Ints(c)
	b := power(2, n)
	a := power(2, n-2)
	ans := 0
	for i := 2; i <= n+1; i++ {
		val := a * int(i) % mod
		val *= c[n+1-i]
		val %= mod
		ans += val
		ans %= mod
	}
	ans *= b
	ans %= mod
	fmt.Println(ans)
}

func readArray(reader *bufio.Reader) []string {
	line, _ := reader.ReadString(' ')
	line = line[:len(line)-1]
	return strings.Split(line, " ")
}

func power(x, n int) int {
	if n == 0 {
		return 1
	}
	mod := int(math.Pow(10, 9)) + 7
	val := power(x, n/2)
	val = val * val % mod
	if n%2 == 1 {
		val = val * x % mod
	}
	return val
}


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
	fmt.Println("Enter the number of elements in the array")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the elements of the array")
	c := make([]int, n)
	for i := 0; i < n; i++ {
		c[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	}
	reader.ReadString('\n')
	if n == 1 {
		fmt.Println(c[0] * 2)
		return
	}
	sort.Slice(c, func(i, j int) bool { return c[i] < c[j] })
	b := power(2, n)
	a := power(2, n-2)
	ans := 0
	for i := 2; i <= n+1; i++ {
		val := a * i % 1000000007
		val *= c[n+1-i]
		val %= 1000000007
		ans += val
		ans %= 1000000007
	}
	ans *= b
	ans %= 1000000007
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


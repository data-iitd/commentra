package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scanf("%d\n", &n)
	a := make([]int, n)
	acc := make([]int, n + 1)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d\n", &a[i])
		acc[i + 1] = acc[i] + a[i]
		acc[i + 1] %= 1000000007
	}
	ans := 0
	for i := 0; i < n; i++ {
		ans += a[i] * (1000000007 + acc[n] - acc[i + 1]) % 1000000007
		ans %= 1000000007
	}
	fmt.Println(ans)
}


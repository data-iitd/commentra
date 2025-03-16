
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
	fmt.Scan(&n)
	var s1, str string
	fmt.Scan(&s1, &str)
	var cnt int
	var b [200 + 10]byte
	for i := 0; i < n; i++ {
		b[cnt] = str[i]
		cnt++
	}
	for i := 0; i < n; i++ {
		b[cnt] = s1[i]
		cnt++
	}
	getFail(b, cnt)
	var len int
	len = min(f[cnt], min(n, n))
	fmt.Println(2*n - len)
}

func getFail(b []byte, m int) {
	var j int
	f[0] = f[1] = 0
	for i := 2; i <= m; i++ {
		for j > 0 && b[j+1] != b[i] {
			j = f[j]
		}
		if b[j+1] == b[i] {
			j++
		}
		f[i] = j
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}


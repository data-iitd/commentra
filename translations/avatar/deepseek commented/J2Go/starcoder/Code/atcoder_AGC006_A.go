
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
	var n int
	var s1, str string
	fmt.Fscanln(reader, &n)
	fmt.Fscanln(reader, &s1)
	fmt.Fscanln(reader, &str)
	b := make([]byte, 2*n)
	cnt := 0
	for i := 0; i < n; i++ {
		b[cnt] = str[i]
		cnt++
	}
	for i := 0; i < n; i++ {
		b[cnt] = s1[i]
		cnt++
	}
	f := make([]int, cnt)
	f[0] = 0
	f[1] = 0
	j := 0
	for i := 2; i <= cnt; i++ {
		for j > 0 && b[j+1]!= b[i] {
			j = f[j]
		}
		if b[j+1] == b[i] {
			j++
		}
		f[i] = j
	}
	len := min(f[cnt], min(n, n))
	fmt.Println(2*n - len)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}


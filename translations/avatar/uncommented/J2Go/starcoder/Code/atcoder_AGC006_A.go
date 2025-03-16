package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var (
		n   int
		s1  string
		str string
		cnt int
	)
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &n)
	s1 = strings.TrimSpace(reader.ReadString('\n'))
	str = strings.TrimSpace(reader.ReadString('\n'))
	b := make([]byte, 2*n+10)
	for i := 0; i < n; i++ {
		b[i] = str[i]
	}
	for i := 0; i < n; i++ {
		b[n+i] = s1[i]
	}
	f := make([]int, 2*n+10)
	f[0] = f[1] = 0
	j := 0
	for i := 2; i <= 2*n; i++ {
		for j > 0 && b[j+1]!= b[i] {
			j = f[j]
		}
		if b[j+1] == b[i] {
			j++
		}
		f[i] = j
	}
	len := min(f[2*n], min(n, n))
	fmt.Println(2*n - len)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}


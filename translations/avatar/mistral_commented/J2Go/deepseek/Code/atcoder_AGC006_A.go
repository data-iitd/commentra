package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const N = 210

var (
	f    [N]int
	b    [N]rune
)

func getFail(b []rune, m int) {
	j := 0
	f[0], f[1] = 0, 0

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

func main() {
	reader := bufio.NewReader(os.Stdin)
	scanner := bufio.NewScanner(reader)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	s1 := scanner.Text()
	scanner.Scan()
	str := scanner.Text()

	cnt := 0

	for i := 0; i < n; i++ {
		cnt++
		b[cnt] = rune(str[i])
	}
	for i := 0; i < n; i++ {
		cnt++
		b[cnt] = rune(s1[i])
	}

	getFail(b[:cnt+1], cnt)

	len := min(f[cnt], min(n, n))

	fmt.Println(2*n - len)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}


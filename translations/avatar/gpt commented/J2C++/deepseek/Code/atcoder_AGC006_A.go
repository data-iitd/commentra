package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const N = 210

var f [N]int
var b [N]rune

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
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	n := readInt(reader)
	s1 := readString(reader)
	str := readString(reader)
	cnt := 0

	for i := 0; i < n; i++ {
		b[++cnt] = rune(str[i])
	}
	for i := 0; i < n; i++ {
		b[++cnt] = rune(s1[i])
	}

	getFail(b[:cnt+1], cnt)

	len := min(f[cnt], min(n, n))
	fmt.Fprintln(writer, 2*n-len)
}

func readString(reader *bufio.Reader) string {
	str, _ := reader.ReadString('\n')
	str = strings.TrimSpace(str)
	return str
}

func readInt(reader *bufio.Reader) int {
	numStr, _ := reader.ReadString('\n')
	num, _ := strconv.Atoi(strings.TrimSpace(numStr))
	return num
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

